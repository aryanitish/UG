library(FactoMineR)
library(imager)
library(png)
cover.img<-readPNG("/home/nitish/Desktop/R_stuff/scripts/coverMessage/dollar.png")
dim(cover.img)
message.img<-readPNG("/home/nitish/Desktop/R_stuff/scripts/coverMessage/womanFace.png")
dim(message.img)

cover.img.pca<-PCA(cover.img,ncp = Inf)
#eigen value have three columns in PCA table, the first col. contains eig values
length(cover.img.pca$eig)/3 
print.PCA(cover.img.pca,file = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/coverImgPca.csv")

message.img.pca<-PCA(message.img,ncp = Inf)
message.img.pca$eig
print.PCA(message.img.pca,file = "/home/nitish/Desktop/R_stuff/scripts/messageImgPca.csv")

cpy.cover.img.pca.eig<- cover.img.pca$eig
#fitting message's pcs in cover's, in last 199, with scaling(divide by highest eigen of cover)
for (i in 300:(length(cover.img.pca$eig)/3)) {
  cover.img.pca$eig[i] = message.img.pca$eig[i-299]/cover.img.pca$eig[1]
}
print.PCA(cover.img.pca,file = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/coverImgPcaSteg.csv")

cover.reconst.pca<-reconst(cover.img.pca)
plot(as.cimg(cover.reconst.pca))
writePNG(cover.reconst.pca,target = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/cvrMsgReconst299n199.png")

#Recalculating PCA to obtain message from cover
re.img<-readPNG("/home/nitish/Desktop/R_stuff/scripts/coverMessage/cvrMsgReconst299n200.png")
dim(re.img)
re.cover.pca<-PCA(re.img,ncp = Inf)
print.PCA(re.cover.pca,file = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/reCoverPca.csv")
re.cover.reconst.pca<-reconst(re.cover.pca)
plot(as.cimg(re.cover.reconst.pca))
writePNG(re.cover.reconst.pca,target = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/StegRecCovImg.png")
#taking eigenvalues from reconstructed pca to obtain eigenvalues of message image and forming an image
message.img.pca.copy<- message.img.pca
for (i in 1:201) {
    message.img.pca.copy$eig[i]<- re.cover.pca$eig[i+299] * cover.img.pca$eig[1]
}
write.csv(message.img.pca.copy$eig,file = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/StegObtndMsgPca.csv")
re.message.img<-reconst(message.img.pca.copy)
plot(as.cimg(re.message.img),main = "final message recieved")
writePNG(re.message.img,target = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/StegRecMesgImg.png")
#trying different scaling to get meaningful message
message.img.pca.copy<- message.img.pca
for (i in 1:201) {
  message.img.pca.copy$eig[i]<- re.cover.pca$eig[i+299] * 655.853314528
}
re.message.img<-reconst(message.img.pca.copy)
plot(as.cimg(re.message.img),main = "final message recieved")
writePNG(re.message.img,target = "/home/nitish/Desktop/R_stuff/scripts/coverMessage/StegRecMesgImgv655scl.png")

#Comparing eigen values of message img before and after stegnongraphing (unscaled)
message.pca.compare<-matrix(data = NA,nrow = 200,ncol = 1)
for (i in 1:200) {
  message.pca.compare[i]<-  message.img.pca$eig[i]/cover.img.pca$eig[1] - re.cover.pca$eig[i+299]
}
message.pca.compare
for (i in 1:200) {
  message.img.pca.copy$eig[i]<- (re.cover.pca$eig[i+299] - message.pca.compare[i]) * cover.img.pca$eig[1]
  
}
re.message.img<-reconst(message.img.pca.copy)
plot(as.cimg(re.message.img),main = "final message recieved changed")
