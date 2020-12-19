library(imager)
img <- load.image("/home/nitish/Desktop/R_stuff/freqFilt/satti/board.tif")
plot(img)

# IDEAL LOW PASS
img.fft <- fft(img)
class(img.fft)
img.fft.matrix <- as.matrix(img.fft)
class(img.fft.matrix)
for (i in 1:nrow(img.fft.matrix)) {
  for (j in 1:ncol(img.fft.matrix)) {
    if(abs(img.fft.matrix[i,j]) < 200)
      img.fft.matrix[i,j] = 0
  }
}
final.img <- fft(img.fft.matrix, inverse = TRUE)

plot(Im(final.img))
final.img <- as.cimg(final.img)%>%abs
class(final.img)
plot(final.img,main = "Ideal Low pass filtered image")

# IDEAL HIGH PASS (only the sign inside for-loop comparison is changed)

img.fft <- fft(img)
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
plot(final.img,main = "Ideal High pass filtered image")
save.image(final.img,"/home/nitish/Desktop/R_stuff/aaHPfiltered.png")

# Since the first value of the matrix(i.e at 1,1) is the DC component of the image, it is the sum of all pixel values.
# To find the average we just divide fft[1,1] by total no. of pixels.
img.fft<-fft(img)
avg.img <- abs(img.fft[1,1]) / (nrow(img) * ncol(img))
avg.img
