library(imager)

img=load.image("/home/nitish/Desktop/R_stuff/scripts/dollar.tif")
plot(img)
mat=as.matrix(img)
for (i in 1:nrow(img)) {
  for (j in 1:ncol(img)) {
    if(mat[i,j]<0.5)
      mat[i,j]=0
    else
      mat[i,j]=1
  }
}
plot(as.cimg(mat))

matt=matrix(1,nrow(img),ncol(img))
i=bitwXor(mat,matt) 
plot(as.cimg(i))
