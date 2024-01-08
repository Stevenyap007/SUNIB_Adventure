types <- c("Java", "C", "Kotlin", "Swift", "Go", "R", "Python")
likes <- c(560,289,35,723,148,362,228)

# pie chart
# pie()

freq = likes * 100 / sum(likes)

freq

pie(likes, radius = 1, 
    main = "programming Languages Total Likes", 
    labels = paste(round(freq),"%"), 
    col = rainbow(length((types)))
    )

# Legends
legend("topleft", types, fill = rainbow(length(types)), cex = 0.8)

# Bar plot
# barplot()

barplot(likes, 
        names.arg = types,
        main = "Programming Languages Total Likes",
        xlab = "Programming Languages",
        ylab = "Total Likes",
        col = rainbow(length(types)))

# Histogram
# hist()

hist(likes,
     main = "Histogram",
     xlab = "total Likes",
     col = "lightblue",
     breaks = 5
     )


# Line Graph
# plot()
# l = line
# p = dot
# o = line + dot
plot(likes, 
     type = "o",
     main = "Line Graph",
     ylab = "Total likes",
     xaxt = "n",
     col = "green"
     )
axis(1, at = 1:length(types), labels = types)

# boxplot
# min, max, quartile, quartile3, median
# boxplot
boxplot(likes,
        main = "Box Plot",
        col = "pink")

# library ggplot2

library(ggplot2)

data <- data.frame(
  types = c("Java", "C", "Kotlin", "Swift", "Go", "R", "Python"),
  likes = c(560,289,35,723,148,362,228)
)

# Pie Chart
ggplot(data, 
       aes(x = "",
           y = likes,
           fill = types)) + 
  geom_bar(stat = "identity") + 
  coord_polar(theta = "y") + 
  theme_void()

# Bar Chart
ggplot(data,
       aes(x = types,
           y = likes,
           fill = types)) +
  geom_bar(stat = "identity") + labs(title = "Bar Plot",
          x = "Programming Languages")+
  theme(legend.position = "left") +
  theme_minimal()

# Histogram

ggplot(data, aes(x = likes)) +
  geom_histogram(binwidth = 200, fill = "lightblue", col = "black")

# Line Graph
ggplot(data, aes(x = types, y = likes, group = 1))+
  geom_point(color = "green") + 
  geom_line(color = "green") +
  theme_bw()

# Box plot
ggplot(data, aes(x = "", y = likes)) +
  geom_boxplot(fill = "pink") +
  labs(title = "Box Plot", y = "total Likes")























