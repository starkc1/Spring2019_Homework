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
          "Jan" = "01",
          "Feb" = "02",
          "Mar" = "03",
          "Apr" = "04",
          "May" = "05",
          "Jun" = "06",
          "Jul" = "07",
          "Aug" = "08",
          "Sep" = "09",
          "Oct" = "10",
          "Nov" = "11",
          "Dec" = "12"
        )
      ),
      selectInput(
        "Day",
        h4("Select Day"),
        choices = list(
          "01",
          "02",
          "03",
          "04",
          "05",
          "06",
          "07",
          "08",
          "09",
          "10",
          "11",
          "12",
          "13",
          "14",
          "15",
          "16",
          "17",
          "18",
          "19",
          "20",
          "21",
          "22",
          "23",
          "24",
          "25",
          "26",
          "27",
          "28",
          "29",
          "30",
          "31"
        )
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
        placeholder = "Enter Airport Code"
      ),
      textInput(
        "dest",
        h4("Destination Airport"),
        placeholder = "Enter Airport Code"
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
  observeEvent(input$search, {
    df = read.xlsx("data.xlsx", sheet = 1, colNames = TRUE, detectDates = TRUE)
    
    filtered <- filter(df, Origin == input$origin, Dest == input$dest, Date == paste("2017-",input$Month,"-",input$Day,"-", sep=""))
    #filtered <- filter(df, Origin == "DFW", Date == "2017-01-04", Dest == "MCO")
    print(filtered)
  })

}

shinyApp(ui, server)