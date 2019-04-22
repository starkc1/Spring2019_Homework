var app = angular.module('VacationPlanner', []).constant('_', _);;

app.controller('MainController', ['$scope', '$http', function ($scope, $http) {
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
            "totalCancels": "",
            "percentTotal": ""
        }
    ]

    $scope.fareResults = [
        {
            "fareMean" : "",
            "fareStd" : "",
        }
    ]



    $scope.resultList = [];

    $scope.airlineList = [];
    $http({
        method: "GET",
        url: "./js/data/Delay_Jan.json"
    }).then(function (response) {
        _.forEach(response.data.January, function (value) {
            if (_.indexOf($scope.airlineList, value.Carrier, 0) == -1) {
                $scope.airlineList.push(value.Carrier);
            }
        })
        //console.log($scope.airlineList);
        $scope.loading = false;
    })

    $scope.selectAirline = function (selected) {
        $scope.airline = selected;
    }

    $scope.search = function () {

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
                "totalCancels": "",
                "percentTotal": ""
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
                //console.log("1")
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Jan.json"
                }).then(function (response) {
                    _.forEach(response.data.January, function (data) {
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
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q1_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q1, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "2":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Feb.json"
                }).then(function (response) {
                    _.forEach(response.data.February, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q1_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q1, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "3":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Mar.json"
                }).then(function (response) {
                    _.forEach(response.data.March, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q1_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q1, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "4":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Apr.json"
                }).then(function (response) {
                    _.forEach(response.data.April, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q2_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q2, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "5":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_May.json"
                }).then(function (response) {
                    _.forEach(response.data.May, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q2_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q2, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "6":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Jun.json"
                }).then(function (response) {
                    _.forEach(response.data.June, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q2_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q2, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "7":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Jul.json"
                }).then(function (response) {
                    _.forEach(response.data.July, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q3_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q3, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "8":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Aug.json"
                }).then(function (response) {
                    _.forEach(response.data.August, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q3_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q3, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "9":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Sep.json"
                }).then(function (response) {
                    _.forEach(response.data.September, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q3_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q3, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "10":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Oct.json"
                }).then(function (response) {
                    _.forEach(response.data.October, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                })


                $http({
                    method: "GET",
                    url: "./js/data/Q4_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q4, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "11":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Nov.json"
                }).then(function (response) {
                    _.forEach(response.data.November, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                })

                $http({
                    method: "GET",
                    url: "./js/data/Q4_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q4, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;
            case "12":
                $http({
                    method: "GET",
                    url: "./js/data/Delay_Dec.json"
                }).then(function (response) {
                    _.forEach(response.data.December, function (data) {
                        if (
                            data.Date == flightDate &&
                            data.Carrier == $scope.airline &&
                            data.Origin == $scope.origin &&
                            data.Dest == $scope.dest
                        ) {
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                })


                $http({
                    method: "GET",
                    url: "./js/data/Q4_Fares.json"
                }).then(function (response) {
                    //console.log(response);
                    _.forEach(response.data.Q4, function (data) {
                        if (data.Airport == $scope.origin) {
                            $scope.fareList.push(parseFloat(data.Fare));
                        }
                    })
                    //console.log($scope.fareList);
                    $scope.performFareMath($scope.fareList);
                })
                break;

        }
        //console.log(moment($scope.flightDate).format("M/D/YY") + " " + $scope.airline + " " + $scope.origin +  " " + $scope.dest);
    }


    //#region Fares
    $scope.performFareMath = function (data) {
        $scope.findAverageFare(data);
        $scope.findStdDevFare(data);

        $scope.fareLoading = false;
    }

    $scope.findAverageFare = function (data) {
        $scope.fareResults[0].fareMean = "Average Cost Of Air Fare: $" + _.round(_.mean(data), 1);
    }

    $scope.findStdDevFare = function(data) {
        $scope.fareResults[0].fareStd = "Standard Deviation Of Air Fares: $" + _.round(ss.standardDeviation(data),1);
    }
    //#endregion
   

    //#region Delay and Cancel
    $scope.performDelayMath = function (data) {
        $scope.findMean(data);
        $scope.countTotalFlights(data);
        $scope.findMaxDelay();
        $scope.findStdDev(data);
        $scope.findProb(data);
        $scope.findCancels($scope.cancelList);
        $scope.delayLoading = false;
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

    $scope.probDelay
    $scope.probDelay_0;
    $scope.probDelay_20;
    $scope.probDelay_40;
    $scope.findProb = function (data) {
        var delayStd = ss.standardDeviation(data);
        var delayMean = ss.mean(data);
        $scope.delayResults[0].probDelay_0 = "Probability of Flight Departing on-time or earlier: " + _.round(jStat.normal.cdf(0, delayMean, delayStd), 1) * 100 + "%";
        $scope.delayResults[0].probDelay_20 = "Probability of Flight Departing 20 mins late or earlier: " + _.round(jStat.normal.cdf(20, delayMean, delayStd), 1) * 100 + "%";
        $scope.delayResults[0].probDelay_40 = "Probability of Flight Departing 40 mins late or earlier: " + _.round(jStat.normal.cdf(40, delayMean, delayStd), 1) * 100 + "%";
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