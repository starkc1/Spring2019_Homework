library(shiny)
library(shinydashboard)
library(dplyr)
library(openxlsx)
library(shinycssloaders)
library(shinyjs)


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
    useShinyjs(),
    fluidRow(
      div(
        id = "start",
        h1("To Begin, Run A Search")
      ),
      hidden(
        div(
          id = "main",
          box(
            title = "Flight Delay/Cancel Probabilty",
            solidHeader = TRUE,
            status = "primary",
            withSpinner(textOutput("delay"), type = 3, color = "#3c8dbc", color.background = "#FFF")
          ),
          box(
            title = "Flight Fares",
            solidHeader = TRUE,
            status = "primary",
            h3("Average Fare")
          )
        )
      )
      
      #,dataTableOutput("table")
    )
  )
)

server <- function(input, output, session) {
  observeEvent(input$search, {
    hide("start")
    show("main") 
    
    sheetNum <- switch(
      input$Month,
      "01" = 1,
      "02" = 2,
      "03" = 3,
      "04" = 4,
      "05" = 5,
      "06" = 6,
      "07" = 7,
      "08" = 8,
      "09" = 9,
      "10" = 10,
      "11" = 11,
      "12" = 12
    )
    
    df = read.xlsx("DelayCancelData.xlsx", sheet = 1, colNames = TRUE, detectDates = TRUE)
    
    filtered <- data.frame(filter(
      df, 
      Carrier == input$Airline, 
      Origin == input$origin, 
      Dest == input$dest, 
      Date == paste("2017-",input$Month,"-",input$Day,"-", sep="") | Date == paste("2018-",input$Month,"-",input$Day,"-", sep="")
    ))
    
    averageDelay <- mean(as.numeric(filtered$Delay), na.rm = TRUE)
    print(averageDelay)
    output$delay <- renderText({paste("Total Delay: ", averageDelay, sep="")})
    
    #output$table <- renderDataTable(filtered)
  })

}

shinyApp(ui, server)