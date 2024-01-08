# na.strings : string apa yang akan kita perlakukan sebagai NA
data <- read.csv('D:/03/Exchange Rate.csv',na.strings = "")
# hilangkan data yang bervalue NA
data <- na.omit(data)
data.filtered <- subset(data, data$Price >= 0)

#devide data
data.filtered.BTC <- subset(data.filtered$BTC > 0)