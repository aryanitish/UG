library(FactoMineR)
library(imager)
library(png)
egg<-readPNG("/home/nitish/Desktop/R_stuff/scripts/dollar.png")
dim(egg)
egg
egg.pca<-PCA(egg,ncp = Inf)
summary(egg.pca)
egg.reconst.pca<-reconst(egg.pca)
plot(as.cimg(egg.reconst.pca))
for (i in 10:length(egg.pca$eig)) {
  egg.pca$eig[i]<-20
}
egg.pca$eig
writePNG(egg.reconst.pca,target = "/home/nitish/Desktop/R_stuff/scripts/dollarReconstPCA20.png")
print.PCA(egg.pca,file = "/home/nitish/Desktop/R_stuff/scripts/dollarPCA100.csv")
dollarPCAreconst<-readPNG("/home/nitish/Desktop/R_stuff/scripts/dollarReconstPCAfullDim.png")
dollarPCAreconst2<-readPNG("/home/nitish/Desktop/R_stuff/scripts/dollarReconstPCAfullDim.png")

dollarPCAreconstStg<-readPNG("/home/nitish/Desktop/R_stuff/scripts/dollarReconstPCA100Steg.png")
diff<-dollarPCAreconst - dollarPCAreconstStg
difforg<- dollarPCAreconst - dollarPCAreconst2
nzero<-0
typeof(diff)
dim(diff)
for (i in 1:nrow(difforg)) {
  for (j in 1:ncol(difforg)) {
    if((difforg[i,j] < 0) || (difforg[i,j] > 0)){
      nzero = nzero + 1
    print(difforg[i,j])
      }
  }
}