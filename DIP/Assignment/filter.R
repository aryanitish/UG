library(imager)
library(png)
### applying filter by manual methods
#fofx<-as.cimg(fofx)
#fofx<-as.cimg(1:9,x=3,y=3)
filter.func<-function(fofx,img.filter)
{
    fofx<-as.matrix(fofx)
    #padding image with a boundary of 0's
    padded.fofx<-matrix(0,nrow = nrow(fofx)+2,ncol = ncol(fofx)+2)
    for (i in 1:nrow(fofx)) {
      for (j in 1:ncol(fofx)) {
        padded.fofx[i+1,j+1] = fofx[i,j]
      }
    }
    
    #filling the 0's padding with neighbouring pixels
    for (i in 1:ncol(padded.fofx)) {
        padded.fofx[1,i] = padded.fofx[2,i]
        padded.fofx[nrow(padded.fofx),i] = padded.fofx[nrow(padded.fofx)-1,i]
    }
    
    for (i in 1:nrow(padded.fofx)) {
      padded.fofx[i,1] = padded.fofx[i,2]
      padded.fofx[i,ncol(padded.fofx)] = padded.fofx[i,ncol(padded.fofx)-1]
    }
    
    #function to calculate sum of products
    sop<- function(x,y) {
      val<-0
      for (i in -1:1) {
        for (j in -1:1) {
          val = val + padded.fofx[x+i,y+j] * img.filter[2+i,2+j]
        }
      }
      return(val)
    }
    
    final.fofx<-matrix(0,nrow = nrow(fofx)+2,ncol = ncol(fofx)+2)
    #applying filter on padded image
    for (i in 2:(nrow(padded.fofx)-1)) {
      for (j in 2:(ncol(padded.fofx)-1)) {
        final.fofx[i,j] = sop(i,j)
      }
    }
    
    plot(as.cimg(final.fofx))
}

lena.img<-load.image("/home/nitish/Desktop/R_stuff/woman_blonde.tif")
filtered.img<-filter.func(lena.img,laplacian)
threshold(filtered.img,"90%")%>%plot

lena.color.img<- load.image("/home/nitish/Desktop/R_stuff/lena_color_512.tif")
plot(lena.color.img)
threshold(lena.color.img,"auto")%>%plot

R.lena.color.img<-filter.func(R(lena.color.img),laplacian)

G.lena.color.img<-filter.func(G(lena.color.img),laplacian)

B.lena.color.img<-filter.func(B(lena.color.img),laplacian)

lena.color.reconst.img<-imappend(list(R.lena.color.img,G.lena.color.img,B.lena.color.img),'c')
plot(lena.color.reconst.img)

threshold(lena.color.reconst.img,"auto")%>%plot

avg<-matrix(c(0,2,0, 2,4,2, 0,2,0),3,3)/16
laplacian<-matrix(c(-1,2,-1, -1,2,-1, -1,2,-1),3,3)

R.lena.color.img<-filter.func(R(lena.color.reconst.img),avg)

G.lena.color.img<-filter.func(G(lena.color.reconst.img),avg)

B.lena.color.img<-filter.func(B(lena.color.reconst.img),avg)
lena.color.reconst.img<-imappend(list(R.lena.color.img,G.lena.color.img,B.lena.color.img),'c')
plot(lena.color.reconst.img)
threshold(lena.color.reconst.img,"auto")%>%plot
lena.color.reconst.img<-imappend(list(R.lena.color.img,G.lena.color.img,B.lena.color.img),'c')
plot(lena.color.reconst.img)

lena.final.img<-imappend(list(threshold(B(lena.color.reconst.img),"auto"),threshold(G(lena.color.reconst.img),"auto"),threshold(R(lena.color.reconst.img),"auto")),'c')
plot(lena.final.img)
plot(filter.func(threshold(grayscale(lena.final.img),"10%"),avg))
