library(imager)
img=load.image("board.tif")
img
plot(img)
imgmat=as.matrix(img)
rows=nrow(imgmat)
cols=ncol(imgmat)
nr=log2(rows)
nc=log2(cols)
p=2^ceiling(nr)
q=2^ceiling(nc)
pad_img=matrix(0,p,q)
for(i in 1:nrow(imgmat))
{
  for(j in 1:ncol(imgmat))
  {
    pad_img[i,j]=imgmat[i,j]
  }
}
dim(pad_img)

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
img.fft <- fft(pad_img)
class(img.fft)
img.fft.matrix <- as.matrix(img.fft)
class(img.fft.matrix)
for (i in 1:nrow(img.fft.matrix)) {
  for (j in 1:ncol(img.fft.matrix)) {
    if(abs(img.fft.matrix[i,j]) > 200)
      img.fft.matrix[i,j] = 0
  }
}
final.img <- fft(img.fft.matrix, inverse = TRUE)
final.img <- as.cimg(final.img)%>%abs
class(final.img)
final.img.mat=as.matrix(final.img)
for(i in 1:nrow(final.img.mat))
{
  for(j in 1:ncol(final.img.mat))
  {
    final.img.mat[i,j]=final.img.mat[i,j]*((-1)^(i+j))
  }
}
new.final.fft.mat=matrix(0,rows,cols)
for(i in 1:nrow(new.final.fft.mat))
{
  for(j in 1:ncol(new.final.fft.mat))
  {
    new.final.fft.mat[i,j]=final.img.mat[i,j]
    
  }
}
plot(img)
plot(as.cimg(new.final.fft.mat))
