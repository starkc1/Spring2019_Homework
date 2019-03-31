library(shiny)
library(shinydashboard)
library(dplyr)
library(openxlsx)


ui <- dashboardPage(

  dashboardHeader(
    title = "Vacation Planner"
  ),
  dashboardSidebar(
    wellPanel(
      h3("Flight Date"),
      selectInput(
        "Month",
        h4("Select Month"),
        choices = list(
          "Jan" = 1,
          "Feb" = 2
        )
      ),
      numericInput(
        "day",
        h4("Select Day"),
        value = 1
      )
    ),
    wellPanel(
      h3("Flight Information"),
      selectInput(
        "Airline",
        h4("Select Airline"),
        choices = list(
          "American Airlines" = "AA",
          "United Airlines" = "UA",
          "Delta" = "DL"
        )
      ),
      textInput(
        "origin",
        h4("Origin Airport"),
        value = "Ex: DFW or LAX"
      ),
      textInput(
        "dest",
        h4("Destination Airport"),
        value = "Ex: DFW or LAX"
      )
    ),
    actionButton(
      "search",
      "Search"
    )
  ),
  dashboardBody(
    tags$head(
      tags$link(rel = "stylesheet", type = "text/css", href = "style.css")
    ),
    fluidRow(
      
    )
  )
)

server <- function(input, output, session) {
  #df = read.xlsx("data.xlsx", sheet = 1, colNames = TRUE, detectDates = TRUE)
  #filtered <- filter(df, Origin == "DFW", Date == "2017-01-04", Dest == "MCO")
  #print(filtered)
}

shinyApp(ui, server)