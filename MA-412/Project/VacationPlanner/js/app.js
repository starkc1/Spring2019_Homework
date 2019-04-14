var app = angular.module('VacationPlanner', []).constant('_', _);;

app.controller('MainController', ['$scope', '$http', function ($scope, $http) {
    $scope.loading = true;
    $scope.delayLoading = false;
    $scope.airline = "Select Airline";
    $scope.flightDate;
    $scope.origin;
    $scope.dest;

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


    // $scope.testDate = "1/1/18";
    // $scope.testCarrier = "AA";
    // $scope.testOrgin = "DFW";
    // $scope.testDest = "SFO";
    // $http({
    //     method: "GET",
    //     url: "./js/data/Delay_Jan.json"
    // }).then(function(response) {
    //     //console.log(response.data.January);
    //     _.forEach(response.data.January, function(value) {
    //         //console.log(value);
    //         if (value.Date == $scope.testDate && value.Carrier == $scope.testCarrier && value.Origin == $scope.testOrgin && value.Dest == $scope.testDest) {
    //             console.log(value);
    //         }
    //     });
    // })

    $scope.selectAirline = function (selected) {
        $scope.airline = selected;
    }

    $scope.search = function () {
        $scope.delayLoading = true;
        $scope.resultList = [];
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
                            $scope.resultList.push(parseInt(data.Delay));
                        }
                    })
                    $scope.performDelayMath($scope.resultList);
                    //console.log($scope.resultList);
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
                break;
            case "8":
                break;
            case "9":
                break;
            case "10":
                break;
            case "11":
                break;
            case "12":
                break;

        }
        //console.log(moment($scope.flightDate).format("M/D/YY") + " " + $scope.airline + " " + $scope.origin +  " " + $scope.dest);
    }

    $scope.performDelayMath = function(data) {
        if (data.length < 2) {
            break;
        } else {
            $scope.findMean(data);
            $scope.countTotalFlights(data);
            $scope.findMaxDelay();
            $scope.findStdDev(data);
            $scope.findVar(data);
            $scope.findSkew(data);
            $scope.delayLoading = false;
        }

    }

    $scope.delayMean;
    $scope.findMean = function(data) {
        $scope.delayMean = "Average Delay of Flights: " + _.round(_.mean(data),1) + " mins";
    }

    $scope.delayStd;
    $scope.findStdDev = function(data) {
        $scope.delayStd = "Standard Deviation of Delays: " + _.round(ss.standardDeviation(data),1) + " mins";
    }

    $scope.delayVar;
    $scope.findVar = function(data) {
        $scope.delayVar = "Variance of Delays: " + _.round(ss.variance(data),1) + " mins";
    }

    $scope.delaySkew;
    $scope.findSkew = function(data) {
        $scope.delaySkew = "Skewness of Delays: " + _.round(ss.sampleSkewness(data), 1);
    }

    $scope.earlyList = [];
    $scope.delayList = [];
    $scope.totalFlights;
    $scope.totalEarlyFlights;
    $scope.totalDelayFlights;
    $scope.countTotalFlights = function(data) {
        $scope.totalFlights = "Total Flights: " + data.length;

        _.forEach(data, function(result) {
            if (result <= 0) {
                $scope.earlyList.push(result);
            } else {
                $scope.delayList.push(result);
            }
        })

        $scope.totalEarlyFlights = "Total Early Departure Flights: " + $scope.earlyList.length;
        $scope.totalDelayFlights = "Total Delayed Departure Flights: " + $scope.delayList.length;
    }

    $scope.maxDelay;
    $scope.findMaxDelay = function() {
        $scope.maxDelay = "Max Delay: " + _.max($scope.delayList) + " mins";
    }

}]);