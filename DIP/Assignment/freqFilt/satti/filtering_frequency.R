#########Ideal low and high pass
library(imager)
img=load.image("/home/satveer/Documents/sem6/DIP/IMAGES/panda.png")
img1=as.matrix(load.image("/home/satveer/Documents/sem6/DIP/IMAGES/p1.png"))
#image=load.image("/home/sakeena_shahid/Downloads/")
img
plot(img,main="Original image")
img_mat=as.matrix(img)
rows=nrow(img_mat)
cols=ncol(img_mat)
nr=log2(rows)
nc=log2(cols)
p=2^ceiling(nr)
q=2^ceiling(nc)
pad_img=matrix(0,p,q)
for(i in 1:nrow(img_mat))
{
  for(j in 1:ncol(img_mat))
  {
    pad_img[i,j]=img_mat[i,j]
  }
}
plot(as.cimg(pad_img),main="Padded image")
#mutiply (-1)
for(i in 1:nrow(pad_img))
{
  for(j in 1:ncol(pad_img))
  {
    pad_img[i,j]=pad_img[i,j]*((-1)^(i+j))
  }
}
plot(as.cimg(pad_img),main="After center")
pad.fft=FFT(as.cimg(pad_img))
plot(pad.fft$real)
plot(pad.fft$imag)
pad.filter=matrix(0,p,q)
for(i in 1:nrow(pad.filter))
{
  for(j in 1:ncol(pad.filter))
  {
    dist=sqrt((i-(p/2))^2+(j-(q/2))^2)
    if(dist<60) #dnote=20
    {
      #pad.filter[i,j]=0#gaussian high pass
      pad.filter[i,j]=1#gaussian low pass
    }
    else
    {
      #pad.filter[i,j]=1#high pass
      pad.filter[i,j]=0#low pass
    }
  }
}
plot(as.cimg(pad.filter))
plot(as.cimg(pad.filter))
filter.fft=list(as.cimg(pad.filter))
final=Map("*",filter.fft,pad.fft)
names(final)=c("real","imag")
plot(final$real)
plot(final$imag)
final.fft=FFT(final$real,final$imag,inverse = TRUE)
plot(final.fft$real)
final.fft.mat=as.matrix(final.fft$real)
#real mul -1
for(i in 1:nrow(final.fft.mat))
{
  for(j in 1:ncol(final.fft.mat))
  {
    final.fft.mat[i,j]=final.fft.mat[i,j]*((-1)^(i+j))
  }
}
plot(as.cimg(final.fft.mat))
#plot(as.cimg(final.fft.mat.im))
new.final.fft.mat=matrix(0,rows,cols)
for(i in 1:nrow(new.final.fft.mat))
{
  for(j in 1:ncol(new.final.fft.mat))
  {
    new.final.fft.mat[i,j]=final.fft.mat[i,j]
    
  }
}
#plot(img)
plot(as.cimg(new.final.fft.mat))
      #save.image(as.cimg(new.final.fft.mat),"/home/satveer/Documents/sem6/DIP/IMAGES/idealhighfiltered.png")


###############Butterworth low and high pass
library(imager)
img=load.image("/home/satveer/Documents/sem6/DIP/IMAGES/aa.tif")
#image=load.image("/home/sakeena_shahid/Downloads/")
img
plot(img,main="Original image")
img_mat=as.matrix(img)
rows=nrow(img_mat)
cols=ncol(img_mat)
nr=log2(rows)
nc=log2(cols)
p=2^ceiling(nr)
q=2^ceiling(nc)
pad_img=matrix(0,p,q)
for(i in 1:nrow(img_mat))
{
  for(j in 1:ncol(img_mat))
  {
    pad_img[i,j]=img_mat[i,j]
  }
}
plot(as.cimg(pad_img),main="Padded image")
#mutiply (-1)
for(i in 1:nrow(pad_img))
{
  for(j in 1:ncol(pad_img))
  {
    pad_img[i,j]=pad_img[i,j]*((-1)^(i+j))
  }
}
plot(as.cimg(pad_img),main="After center")
pad.fft=FFT(as.cimg(pad_img))
plot(pad.fft$real)
plot(pad.fft$imag)
pad.filter=matrix(0,p,q)
for(i in 1:nrow(pad.filter))
{
  for(j in 1:ncol(pad.filter))
  {
    dist=sqrt((i-(p/2))^2+(j-(q/2))^2)  
    pad.filter[i,j]=1/(1+(10/dist)^(2*2))#butterworth high pass Dnote=2
    #pad.filter[i,j]=1/(1+(dist/10)^(2*2))#butterworth low pass Dnote=2
  }
}
plot(as.cimg(pad.filter))
#filter mul -1

plot(as.cimg(pad.filter))
filter.fft=list(as.cimg(pad.filter))
final=Map("*",filter.fft,pad.fft)
names(final)=c("real","imag")
plot(final$real)
plot(final$imag)
final.fft=FFT(final$real,final$imag,inverse = TRUE)
plot(final.fft$real)
final.fft.mat=as.matrix(final.fft$real)
#real mul -1
for(i in 1:nrow(final.fft.mat))
{
  for(j in 1:ncol(final.fft.mat))
  {
    final.fft.mat[i,j]=final.fft.mat[i,j]*((-1)^(i+j))
  }
}
plot(as.cimg(final.fft.mat))
#plot(as.cimg(final.fft.mat.im))
new.final.fft.mat=matrix(0,rows,cols)
for(i in 1:nrow(new.final.fft.mat))
{
  for(j in 1:ncol(new.final.fft.mat))
  {
    new.final.fft.mat[i,j]=final.fft.mat[i,j]
    
  }
}
#plot(img)
plot(as.cimg(new.final.fft.mat))
#save.image(as.cimg(new.final.fft.mat),"/home/satveer/Documents/sem6/DIP/IMAGES/btwhighfiltered.png")
########gaussian high and low pass
library(imager)
img=load.image("/home/satveer/Documents/sem6/DIP/IMAGES/aa.tif")
#image=load.image("/home/sakeena_shahid/Downloads/")
img
plot(img,main="Original image")
img_mat=as.matrix(img)
rows=nrow(img_mat)
cols=ncol(img_mat)
nr=log2(rows)
nc=log2(cols)
p=2^ceiling(nr)
q=2^ceiling(nc)
pad_img=matrix(0,p,q)
for(i in 1:nrow(img_mat))
{
  for(j in 1:ncol(img_mat))
  {
    pad_img[i,j]=img_mat[i,j]
  }
}
plot(as.cimg(pad_img),main="Padded image")
#mutiply (-1)
for(i in 1:nrow(pad_img))
{
  for(j in 1:ncol(pad_img))
  {
    pad_img[i,j]=pad_img[i,j]*((-1)^(i+j))
  }
}
plot(as.cimg(pad_img),main="After center")
pad.fft=FFT(as.cimg(pad_img))
plot(pad.fft$real)
plot(pad.fft$imag)
pad.filter=matrix(0,p,q)
for(i in 1:nrow(pad.filter))
{
  for(j in 1:ncol(pad.filter))
  {
    dist=sqrt((i-(p/2))^2+(j-(q/2))^2)
    
    pad.filter[i,j]=exp(-(dist^2)/(2*(5^2)))#gaussian low pass dnote=5
    #pad.filter[i,j]=1-exp(-(dist^2)/(2*(160^2)))#gaussian high pass  dnote=160
    
  }
}
plot(as.cimg(pad.filter))
filter.fft=list(as.cimg(pad.filter))
final=Map("*",filter.fft,pad.fft)
names(final)=c("real","imag")
plot(final$real)
plot(final$imag)
final.fft=FFT(final$real,final$imag,inverse = TRUE)
plot(final.fft$real)

final.fft.mat=as.matrix(final.fft$real)
#real mul -1
for(i in 1:nrow(final.fft.mat))
{
  for(j in 1:ncol(final.fft.mat))
  {
    final.fft.mat[i,j]=final.fft.mat[i,j]*((-1)^(i+j))
  }
}
plot(as.cimg(final.fft.mat))
new.final.fft.mat=matrix(0,rows,cols)
for(i in 1:nrow(new.final.fft.mat))
{
  for(j in 1:ncol(new.final.fft.mat))
  {
    new.final.fft.mat[i,j]=final.fft.mat[i,j]
    
  }
}
#plot(img)
plot(as.cimg(new.final.fft.mat))
#save.image(as.cimg(new.final.fft.mat),"/home/satveer/Documents/sem6/DIP/IMAGES/gauslowfiltered.png")
####Laplacian
library(imager)
img=load.image("/home/satveer/Documents/sem6/DIP/IMAGES/moon.tif")
#image=load.image("/home/sakeena_shahid/Downloads/")
img
plot(img,main="Original image")
img_mat=as.matrix(img)
rows=nrow(img_mat)
cols=ncol(img_mat)
nr=log2(rows)
nc=log2(cols)
p=2^ceiling(nr)
q=2^ceiling(nc)
pad_img=matrix(0,p,q)
for(i in 1:nrow(img_mat))
{
  for(j in 1:ncol(img_mat))
  {
    pad_img[i,j]=img_mat[i,j]
  }
}
plot(as.cimg(pad_img),main="Padded image")
#mutiply (-1)
#for(i in 1:nrow(pad_img))
#{
 # for(j in 1:ncol(pad_img))
  #{
   # pad_img[i,j]=pad_img[i,j]*((-1)^(i+j))
  #}
#}
plot(as.cimg(pad_img),main="After center")
pad.fft=FFT(as.cimg(pad_img))
plot(pad.fft$real)
plot(pad.fft$imag)
pad.filter=matrix(0,p,q)
for(i in 1:nrow(pad.filter))
{
  for(j in 1:ncol(pad.filter))
  {
    dist=((i-(p/2))^2+(j-(q/2))^2)  
    pad.filter[i,j]=-4*(pi^2)*(dist^2)
    
  }
}
plot(as.cimg(pad.filter))
plot(as.cimg(pad.filter))
filter.fft=list(as.cimg(pad.filter))
final=Map("*",filter.fft,pad.fft)
names(final)=c("real","imag")
plot(final$real)
plot(final$imag)
final.fft=FFT(final$real,final$imag,inverse = TRUE)
plot(final.fft$real)
final.fft.mat=as.matrix(final.fft$real)
#real mul -1
#for(i in 1:nrow(final.fft.mat))
#{
 # for(j in 1:ncol(final.fft.mat))
  #{
   # final.fft.mat[i,j]=final.fft.mat[i,j]*((-1)^(i+j))
  #}
}
plot(as.cimg(final.fft.mat))
#plot(as.cimg(final.fft.mat.im))
new.final.fft.mat=matrix(0,rows,cols)
for(i in 1:nrow(new.final.fft.mat))
{
  for(j in 1:ncol(new.final.fft.mat))
  {
    new.final.fft.mat[i,j]=final.fft.mat[i,j]
    
  }
}
#plot(img)
plot(as.cimg(new.final.fft.mat))


