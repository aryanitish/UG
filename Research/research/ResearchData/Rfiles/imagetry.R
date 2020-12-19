    library(imager)
    library(png)
    library(ggfortify)

    ####
    # Function to calculate PCA of an image and reconstruct the image using lesser components
    # argumetns: pca_arg -> List of pixel values of an image
    #            pcuse -> No. of principal components to use for reconstructing the image
    #            issave -> if TRUE: saves the image, otherwise does not
    PCArestoration<-function(pca_arg,img_nm,pcuse,issave)
    {
        png(filename = paste("/home/nitish/Desktop/R_stuff/scripts/PCAdata/compVSvar/",img_nm,".png"))
        screeplot(pcaimg1<-prcomp(pca_arg),type="lines")
        dev.off()
        dim(pcaimg1)
        #truncating components after 'pcuse' and restoring the image
        truncimg<- pcaimg1$x[,1:pcuse] %*% t(pcaimg1$rotation[,1:pcuse])
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
        
        if(issave==TRUE)
            #SAVING THE OBTAINED IMAGE FROM ORIGINAL[PCA] WITH CORRESPONDING FILENAME
            save.image(FinalImg,paste("/home/nitish/Desktop/R_stuff/scripts/PCAdata/PCAimages/pc50/",img_nm,"PC",pcuse,".png",sep = ""))
        
    }
    PCArestoration2<-function(pca_arg,img_nm,pcuse,issave)
    {
        #png(filename = paste("/home/nitish/Desktop/R_stuff/scripts/PCAdata/compVSvar/",img_nm,".png"))
        screeplot(pcaimg1<-prcomp(pca_arg),type="lines")
        #dev.off()
        dim(pcaimg1)
        #truncating components after 'pcuse' and restoring the image
        truncimg<- pcaimg1$x[,1:pcuse] %*% t(pcaimg1$rotation[,1:pcuse])
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
        
        #if(issave==TRUE)
            #SAVING THE OBTAINED IMAGE FROM ORIGINAL[PCA] WITH CORRESPONDING FILENAME
         #   save.image(FinalImg,paste("/home/nitish/Desktop/R_stuff/scripts/PCAdata/PCAimages/pc50/",img_nm,"PC",pcuse,".png",sep = ""))
        
    }
   
    imgFiles<-list.files("/home/nitish/Desktop/R_stuff/scripts/ResearchData/PCAdata/testIMAGES",pattern = "*.png",full.names = TRUE)
    imgList<-lapply(imgFiles,readPNG)
    length(imgList)
    imgFiles
    #checking there is no loss of image data in .tif to .png conversion and other operations
    plot(as.cimg(imgList[[11]]))
    comp<-50
    PCArestoration2(imgList[[11]],11,comp,TRUE)
    #CALL TO FUNCTION FOR PCA CALCULATION
    for (i in 1:length(imgList)) {
        PCArestoration(imgList[[i]],i,comp,TRUE)
    }
    ncol(imgList[[12]])
    