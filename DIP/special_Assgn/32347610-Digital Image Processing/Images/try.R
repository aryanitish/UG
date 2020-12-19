library(imager)
img <- load.image("/home/nitish/Desktop/DIP/specAssgn/32347610-Digital Image Processing/Images/panda.png")
plot(img)
img <- as.matrix(img)


img2 <- load.image("/home/nitish/Desktop/DIP/specAssgn/32347610-Digital Image Processing/Images/panda_modified.png")
plot(img2)
img2 <- as.matrix(img2)

im <- load.image("/home/nitish/Desktop/DIP/specAssgn/32347610-Digital Image Processing/Images/clock.png") %>% plot
small <- imresize(im, scale = 1/5, interpolation = 1) %>% plot
big <- imresize(small, scale = 5, interpolation = 1) %>% plot
