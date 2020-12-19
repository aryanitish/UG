library(imager)
kpop<-load.image("/home/nitish/Desktop/R_stuff/scripts/dollar.tif")
plot(kpop)
for (i in 1:nrow(kpop)) {
  for (j in 1:ncol(kpop)) {
    kpopInv[i,j] = 1 - kpop[i,j]
  }
  
}
plot(kpopInv)s