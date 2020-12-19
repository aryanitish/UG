library(imager)
library(FactoMineR)
mat <- matrix(5,2,3)
mat
mat.PCA <- PCA(mat)
eig <- mat.PCA$eig
summ <- mat.PCA$call
ind <- mat.PCA$ind
