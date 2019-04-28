var app = angular.module('VacationPlanner', []).constant('_', _).config(function($httpProvider) {
    delete $httpProvider.defaults.headers.common['X-Requested-With'];
});


app.controller('MainController', ['$scope', '$http', '$window', function ($scope, $http, $window) {
    $scope.loading = true;
    $scope.delayLoading = false;
    $scope.fareLoading = false;
    $scope.airline = "Select Airline";
    $scope.flightDate;
    $scope.origin;
    $scope.dest;

    $scope.delayResults = [
        {
            "totalFlights": "",
            "totalEarlyFlights": "",
            "totalDelayFlights": "",
            "delayMean": "",
            "maxDelay": "",
            "delayStd": "",
            "delaySkew": "",
            "probDelay_0": "",
            "probDelay_20": "",
            "probDelay_40": "",
            "confidence_90": "",
            "confidence_95": "",
            "confidence_99": "",
            "totalCancels": "",
            "percentTotal": ""
        }
    ]

    $scope.fareResults = [
        {
            "maxFare" : "",
            "totalFares": "",
            "fareMean" : "",
            "fareStd" : "",
            "fare_200" : "",
            "fare_300" : "",
            "fare_400" : "",
            "fare_500" : "",
            "fareCI_90" : "",
            "fareCI_95" : "",
            "fareCI_99" : ""
        }
    ]

    $scope.airlineList = ["9E", "AA", "AS", "B6", "DL", "EV", "F9", "G4", "HA", "MQ", "NK", "OH", "OO", "UA","WN","YV","YX"]
    $scope.loading = false;


    $scope.resultList = [];


    $scope.q1 = false;
    $scope.q2 = false;
    $scope.q3 = false;
    $scope.q4 = false;
    $scope.Apr = false;
    $scope.Aug = false;
    $scope.Dec = false;
    $scope.Feb = false;
    $scope.Jan = false;
    $scope.Jun = false;
    $scope.Jul = false;
    $scope.Mar = false;
    $scope.May = false; 
    $scope.Nov = false;
    $scope.Oct = false;
    $scope.Sep = false;
    // $scope.airlineList = [];
    // $scope.getAirlines = function(data) {
    //     _.forEach(data, function(value) {
    //         $scope.airlineList.push(value.Carrier);
    //     });
    //     $scope.loading = false;
    //     $scope.Apr = false;
    // }
    // $scope.getAirlines($window.Carriers.Carriers);



    $scope.selectAirline = function (selected) {
        $scope.airline = selected;
    }

    $scope.search = function () {

        $scope.delayError = "";

        $scope.delayResults = [
            {
                "totalFlights": "",
                "totalEarlyFlights": "",
                "totalDelayFlights": "",
                "delayMean": "",
                "maxDelay": "",
                "delayStd": "",
                "delaySkew": "",
                "probDelay_0": "",
                "probDelay_20": "",
                "probDelay_40": "",
                "confidence_90": "",
                "confidence_95": "",
                "confidence_99": "",
                "totalCancels": "",
                "percentTotal": ""
            }
        ]

        $scope.fareResults = [
            {
                "maxFare" : "",
                "totalFares": "",
                "fareMean" : "",
                "fareStd" : "",
                "fare_200" : "",
                "fare_300" : "",
                "fare_400" : "",
                "fare_500" : "",
                "fareCI_90" : "",
                "fareCI_95" : "",
                "fareCI_99" : ""
            }
        ]

        $scope.delayLoading = true;
        $scope.fareLoading = true;
        $scope.resultList = [];
        $scope.delayList = [];
        $scope.earlyList = [];
        $scope.cancelList = [];

        $scope.fareList = [];
        var month = moment($scope.flightDate).format("M").toString();
        var flightDate = moment($scope.flightDate).format("M/D/18").toString();
        switch (month) {
            case "1":

                $scope.Jan = true;
                $scope.q1 = true;
                _.forEach($window.January.January, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);




                _.forEach($window.Q1_Fares.Q1, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "2":

                $scope.Feb = true;
                $scope.q1 = true;
                _.forEach($window.February.February, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q1_Fares.Q1, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "3":
                $scope.Mar = true;
                $scope.q1 = true;
                _.forEach($window.March.March, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q1_Fares.Q1, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "4":

                    $scope.Apr = true;
                    $scope.q2 = true;
                _.forEach($window.April.April, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q2_Fares.Q2, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "5":

                    $scope.May = true;
                    $scope.q2 = true;
                _.forEach($window.May.May, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q2_Fares.Q2, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "6":


                    $scope.Jun = true;
                    $scope.q2 = true;
                _.forEach($window.June.June, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q2_Fares.Q2, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "7":

                    $scope.Jul = true;
                    $scope.q3 = true;
                _.forEach($window.July.July, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q3_Fares.Q3, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "8":


                    $scope.Aug = true;
                    $scope.q3 = true;
                _.forEach($window.August.August, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q3_Fares.Q3, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "9":

                    $scope.Sep = true;
                    $scope.q3 = true;
                _.forEach($window.September.September, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q3_Fares.Q3, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "10":

                    $scope.Oct = true;
                    $scope.q4 = true;
                _.forEach($window.October.October, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q4_Fares.Q4, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "11":

                    $scope.Nov = true;
                    $scope.q4 = true;
                _.forEach($window.November.November, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q4_Fares.Q4, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;
            case "12":


                    $scope.Dec = true;
                    $scope.q4 = true;
                _.forEach($window.December.December, function (data) {
                    if (
                        data.Date == flightDate &&
                        data.Carrier == $scope.airline &&
                        data.Origin == $scope.origin &&
                        data.Dest == $scope.dest
                    ) {
                        if (data.Cancel == 1) {
                            $scope.cancelList.push(parseInt(data.Cancel));
                        } else {
                            $scope.resultList.push(parseInt(data.Delay));
                        }

                    }
                })
                $scope.performDelayMath($scope.resultList);



                
                _.forEach($window.Q4_Fares.Q4, function (data) {
                    if (data.Airport == $scope.origin) {
                        $scope.fareList.push(parseFloat(data.Fare));
                    }
                })
                $scope.performFareMath($scope.fareList);
                break;

        }
        //console.log(moment($scope.flightDate).format("M/D/YY") + " " + $scope.airline + " " + $scope.origin +  " " + $scope.dest);
    }


    //#region Fares
    $scope.performFareMath = function (data) {
        console.log("Fare Data", data);
        $scope.findFareStats(data);
        $scope.findAverageFare(data);
        $scope.findStdDevFare(data);
        $scope.findFareCI(data);
        $scope.findFareProb(data);

        $scope.fareLoading = false;
    }

    $scope.findFareStats = function (data) {
        $scope.fareResults[0].maxFare = "Max Flight Fare: $" + _.round(_.max(data));
        $scope.fareResults[0].totalFares = "Total Amount of Flight Fares: " + data.length;
    }

    $scope.findAverageFare = function (data) {
        $scope.fareResults[0].fareMean = "Average Cost Of Air Fare: $" + _.round(_.mean(data), 1);
    }

    $scope.findStdDevFare = function(data) {
        $scope.fareResults[0].fareStd = "Standard Deviation Of Air Fares: $" + _.round(ss.standardDeviation(data),1);
    }

    $scope.findFareCI = function(data) {
        var fareMean = ss.mean(data);

        var CI_90 = jStat.normalci(fareMean, 0.9, data);
        $scope.fareResults[0].fareCI_90 = "In 90% of samples the average flight fare is between: " + _.round(CI_90[0], 2) + " and " + _.round(CI_90[1], 2);
        var CI_95 = jStat.normalci(fareMean, 0.95, data);
        $scope.fareResults[0].fareCI_95 = "In 95% of samples the average flight fare is between: " + _.round(CI_95[0], 2) + " and " + _.round(CI_95[1], 2);
        var CI_99 = jStat.normalci(fareMean, 0.99, data);
        $scope.fareResults[0].fareCI_99 = "In 99% of samples the average flight fare is between: " + _.round(CI_99[0], 2) + " and " + _.round(CI_99[1], 2);

    }

    $scope.findFareProb = function (data) {
        var fareMean = ss.mean(data);
        var fareStdDev = ss.standardDeviation(data);

        $scope.fareResults[0].fare_200 = "Probability of Flight Fare Being Less Than $200: " + _.round(jStat.normal.cdf(200, fareMean, fareStdDev), 1) * 100 + "%";
        $scope.fareResults[0].fare_300 = "Probability of Flight Fare Being Less Than $300: " + _.round(jStat.normal.cdf(300, fareMean, fareStdDev), 1) * 100 + "%";
        $scope.fareResults[0].fare_400 = "Probability of Flight Fare Being Less Than $400: " + _.round(jStat.normal.cdf(400, fareMean, fareStdDev), 1) * 100 + "%";
        $scope.fareResults[0].fare_500 = "Probability of Flight Fare Being Less Than $500: " + _.round(jStat.normal.cdf(500, fareMean, fareStdDev), 1) * 100 + "%";
    }
    //#endregion
   

    //#region Delay and Cancel
    $scope.performDelayMath = function (data) {
        console.log("Delay Data", data);
        if (data.length > 2) {
            $scope.findMean(data);
            $scope.countTotalFlights(data);
            $scope.findMaxDelay();
            $scope.findStdDev(data);
            $scope.findProb(data);
            $scope.findCI(data);
            $scope.findSignificance(data);
            $scope.findCancels($scope.cancelList);
            $scope.delayLoading = false;
        } else {
            $scope.delayError = "Error Loading Results, probably because the airline does not have flights on the selected route";
            $scope.delayLoading = false;
        }
        
    }

    $scope.findCancels = function (data) {
        $scope.delayResults[0].totalCancels = "Total Canceled Flights: " + data.length;
        $scope.delayResults[0].percentTotal = "Percent Of All Flights Cancelled: " + _.round(data.length / $scope.resultList.length, 1) * 100 + "%";
    }


    $scope.findMean = function (data) {
        $scope.delayResults[0].delayMean = "Average Delay of Flights: " + _.round(_.mean(data), 1) + " mins";
    }

    $scope.delayStd;
    $scope.findStdDev = function (data) {
        $scope.delayResults[0].delayStd = "Standard Deviation of Delays: " + _.round(ss.standardDeviation(data), 1) + " mins";
    }

    $scope.findProb = function (data) {
        var delayStd = ss.standardDeviation(data);
        var delayMean = ss.mean(data);
        $scope.delayResults[0].probDelay_0 = "Probability of Flight Departing on-time or earlier: " + _.round(jStat.normal.cdf(0, delayMean, delayStd), 1) * 100 + "%";
        $scope.delayResults[0].probDelay_20 = "Probability of Flight Departing 20 mins late or earlier: " + _.round(jStat.normal.cdf(20, delayMean, delayStd), 1) * 100 + "%";
        $scope.delayResults[0].probDelay_40 = "Probability of Flight Departing 40 mins late or earlier: " + _.round(jStat.normal.cdf(40, delayMean, delayStd), 1) * 100 + "%";
    }

    $scope.findCI = function (data) {
        var delayMean = ss.mean(data);

        var CI_90 = jStat.normalci(delayMean, 0.9, data);
        $scope.delayResults[0].confidence_90 = "In 90% of samples the average flight delay is between: " + _.round(CI_90[0], 2) + " And " + _.round(CI_90[1], 2);
        var CI_95 = jStat.normalci(delayMean, 0.95, data);
        $scope.delayResults[0].confidence_95 = "In 95% of samples the average flight delay is between: " + _.round(CI_95[0], 2) + " And " + _.round(CI_95[1], 2);
        var CI_99 = jStat.normalci(delayMean, 0.99, data);
        $scope.delayResults[0].confidence_99 = "In 99% of samples the average flight delay is between: " + _.round(CI_99[0], 2) + " And " + _.round(CI_99[1], 2);
    }

    $scope.findSignificance = function (data) {
        var delayMean = ss.mean(data);

        //console.log(jStat.ttest(20, data, 1));

    }

    $scope.earlyList = [];
    $scope.delayList = [];
    $scope.totalFlights;
    $scope.totalEarlyFlights;
    $scope.totalDelayFlights;
    $scope.countTotalFlights = function (data) {
        $scope.delayResults[0].totalFlights = "Total Flights: " + data.length;
        _.forEach(data, function (result) {
            if (result <= 0) {
                $scope.earlyList.push(result);
            } else {
                $scope.delayList.push(result);
            }
        })
        $scope.delayResults[0].totalEarlyFlights = "Total Early Departure Flights: " + $scope.earlyList.length;
        $scope.delayResults[0].totalDelayFlights = "Total Delayed Departure Flights: " + $scope.delayList.length;
    }

    $scope.maxDelay;
    $scope.findMaxDelay = function () {
        $scope.delayResults[0].maxDelay = "Max Delay: " + _.max($scope.delayList) + " mins";
    }
    //#endregion



}]);