library(imager)
library(png)
library(ggfortify)
egg<-load.image("/home/nitish/Desktop/R_stuff/scripts/a.png")
#png(filename="/home/nitish/Desktop/R_stuff/scripts/abc.png")
display(egg)
egg<-readPNG("/home/nitish/Desktop/R_stuff/scripts/a.png")
writePNG(egg,target = "/home/nitish/Desktop/R_stuff/scripts/b.png" )
dim(egg)
egg
eggarr<-R(egg)
eggarb<-B(egg)
eggarg<-G(egg)
eggre<- eggarr+eggarg+eggarb
screeplot(pcaimg1<-prcomp(egg,center = TRUE),npcs = 20,type="lines")
summary(pcaimg1)
ggplot(pcaimg1)
pcuse<-100
#truncating components after 'pcuse' and restoring the image
truncimg<- pcaimg1$x[,1:50] %*% t(pcaimg1$rotation[,1:50])
dim(truncimg)

#and add the center (and re-scale) back to data
if(pcaimg1$scale != FALSE){
  truncimg <- scale(truncimg, center = FALSE , scale=1/pcaimg1$scale)
}
if(pcaimg1$center != FALSE){
  truncimg <- scale(truncimg, center = -1 * pcaimg1$center, scale=FALSE)
}
truncimg<-t(truncimg)
FinalImg<-as.cimg(truncimg)
plot(FinalImg)
