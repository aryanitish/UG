data("LifeCycleSavings")
summary(LifeCycleSavings)
barplot(LifeCycleSavings$pop75,main= "Percentage of people under age 75")
hist(LifeCycleSavings$pop15,xlab = "Percentage of people",main="Histogram of people under age 15",col = "green")
plot(LifeCycleSavings$dpi,type = "o",ylab ="Per-capita disposable income",main = "Line graphp of DPI")
con_name=row.names(LifeCycleSavings)
barplot(LifeCycleSavings$ddpi,names.arg = con_name,main = "% growth rate of DPI",ylab = "Percentage")

