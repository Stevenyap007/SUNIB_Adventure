data <- read.csv('C:/5 - Barbinus Uniheimer/Data mining/LATIHAN/Week 3/Exchange Rate.csv',
                 na.strings = "")
data <- na.omit(data)
data.filtered <- subset(data, data$Price >= 0)

#devide data
data.filtered.BTC <- subset(data.filtered,
                            data.filtered$ï..Cryptocurrency == "BTC" )
data.filtered.ETH <- subset(data.filtered,
                            data.filtered$ï..Cryptocurrency == "ETH" )
data.filtered.XRP <- subset(data.filtered,
                            data.filtered$ï..Cryptocurrency == "XRP" )

data.filtered.BTC <- 
  data.filtered.BTC[order(data.filtered.BTC$Date,data.filtered.BTC$Time),]
data.filtered.ETH <- 
  data.filtered.ETH[order(data.filtered.ETH$Date,data.filtered.ETH$Time),]
data.filtered.XRP <- 
  data.filtered.XRP[order(data.filtered.XRP$Date,data.filtered.XRP$Time),]

# FILTER BY DATE

data.filtered.ETH.16aug <- 
  subset(data.filtered.ETH, data.filtered.ETH$Date == "16-Aug-18")

data.filtered.ETH.16aug$Time <- strptime(data.filtered.ETH.16aug$Time, "%H:%M:%S")
data.filtered.ETH.16aug <- data.filtered.ETH.16aug[order(data.filtered.ETH.16aug$Time),]

data.filtered.ETH.16aug.open <- data.filtered.ETH.16aug$Price[1]
data.filtered.ETH.16aug.close <- data.filtered.ETH.16aug$Price[length(data.filtered.ETH.16aug)]

data.filtered.BTC.15aug <- 
  subset(data.filtered.BTC, data.filtered.BTC$Date == "15-Aug-18")

data.filtered.BTC.15aug.max = 
  max(data.filtered.BTC.15aug$Price)

data.filtered.BTC.15aug.max = 
  min(data.filtered.BTC.15aug$Price)

data.filtered.XRP.18aug = 
  subset(data.filtered.XRP, data.filtered.XRP$Date == "18-Aug-18")

data.filtered.XRP.18aug$Price = as.numeric(data.filtered.XRP.18aug$Price)

summary(data.filtered.XRP.18aug$Price)

mean(data.filtered.XRP.18aug$Price)
median(data.filtered.XRP.18aug$Price)
sd(data.filtered.XRP.18aug$Price)

data$Price <- as.numeric(data$Price)
aggregate(data$Price, by = list(data$ï..Cryptocurrency), FUN = max)
aggregate(data$Price, by = list(data$ï..Cryptocurrency), FUN = min)
aggregate(data$Price, by = list(data$ï..Cryptocurrency), FUN = mean)