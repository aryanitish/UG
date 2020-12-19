# QUESTION 1

# ALL EXTERNAL PACKAGES ----
library(dplyr)
library(tidyr)
library(ggplot2)
library(BSDA)

# I & II ----
setwd("/home/nitish/Desktop/R_stuff/DataSc/PracAsgn")
disaster <- read.csv("Disaster.csv",
                     header = TRUE)
as_tibble(disaster)

# III ----
nrow(disaster)

# IV ----
View(disaster)

# V ----
disaster %>% 
  group_by(ORGANIZATION)

# VI ----
ggplot(disaster, aes(x = TOTAL_ACRES, y = ORGANIZATION)) +
  geom_boxplot()

# VII ----
#Since TOTAL_ACRES gives us a range of numbers, we analyse on it.
outlier <- boxplot(disaster$TOTAL_ACRES)$out 

# VIII ----
disaster %>%
  ggplot() +
  geom_point(mapping = aes(x = LOCALITY, y = TOTAL_ACRES)) +
  facet_null()

# IX ----
#First obtain decade(mutate), then plot.
decade <- disaster %>% 
  mutate(decade = YEAR_ %/% 10 * 10) %>%
  select(decade)
hist(decade$decade,breaks = pretty(1980:2000, n=10), main = "Disasters in past decades", xlab = "Decades", ylab = "Total Disasters", border = "black")
# Clearly, the number of disasters have increased in the past few decades.

# X ----
summary(disaster)

# XI ----
disaster %>% 
  select(END_DATE,START_DATE) %>%  
  filter(!START_DATE == "" , !END_DATE == "") %>% 
  mutate(RECOVERY_TIME = as.Date(END_DATE,format="%m/%d/%Y") - as.Date(START_DATE,format="%m/%d/%Y")) %>% 
  summarise(avg_rec_time = mean(RECOVERY_TIME))

# XII ----
disaster %>% 
  filter(!START_DATE == "" , !END_DATE == "") %>% 
  separate(START_DATE,into = c("MONTH","day","year"), sep="/", convert = TRUE) %>% 
  head()

# XIII ----
disaster %>% 
  filter(!START_DATE == "" , !END_DATE == "") %>% 
  separate(START_DATE,into = c("MONTH","day","year"), sep="/", convert = TRUE) %>% 
  group_by(MONTH) %>% 
  summarise(mean_destr = mean(DESTRUCTION..in.Thousand.Dollars.))

# XIV ----
#read.table() function is most conveniently used in text(.txt) file format.


# XV ----
#Working of both the commands is same.
#read.csv is in the utils package and read_csv is in the readr package.
#read.csv has less arguments than read_csv.


# XVI ----
#base packages:utils,graphics,BSDA.
#third party:dplyr,ggplot2.


# XVII ----
#Z-test could be performed in two variables.
#DESTRUCTION..in.Thousand.Dollars. ,  TOTAL_ACRES.


# XVIII ----
z.test(disaster$DESTRUCTION..in.Thousand.Dollars.,sigma.x = sd(disaster$DESTRUCTION..in.Thousand.Dollars.))


# XIX ----
#We could check the data by shapiro wilk test for normal distribution and by plotting the graph.  


# XX ----
# We can change the values of the numeric columns to the common scale.  

