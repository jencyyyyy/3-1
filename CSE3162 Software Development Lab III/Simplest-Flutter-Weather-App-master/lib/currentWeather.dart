import 'dart:convert';
import 'package:flutter/material.dart';
import 'models/weather.dart';
import 'package:http/http.dart' as http;

class CurrentWeatherPage extends StatefulWidget {
  const CurrentWeatherPage({Key? key}) : super(key: key);

  @override
  State<CurrentWeatherPage> createState() => _CurrentWeatherPageState();
}

class _CurrentWeatherPageState extends State<CurrentWeatherPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: FutureBuilder(
          builder: (BuildContext context, AsyncSnapshot snapshot) {
            if (snapshot != null) {
              print(snapshot);
              Weather _weather = snapshot.data;
              print("Akif ! Weather :  ${_weather}");

              if (_weather == null) {
                return Text("Error getting weather");
              } else {
                return weatherBox(_weather);
              }
            } else {
              return CircularProgressIndicator();
            }
          },
          future: getCurrentWeather(),
        ),
      ),
    );
  }
}

Widget weatherBox(Weather _weather) {
  return Column(mainAxisSize: MainAxisSize.min, children: <Widget>[
    Container(
      margin: const EdgeInsets.all(10),
      child: Text(
        "${_weather.temp} C",
        textAlign: TextAlign.center,
        style: TextStyle(fontWeight: FontWeight.bold, fontSize: 55),
      ),
    ),
    Text("${_weather.feelsLike}"),
    Text("H:${_weather.high}C L:${_weather.low}C"),
    Container(
        child: Text(
      "${_weather.description}",
      style: TextStyle(fontWeight: FontWeight.bold, fontSize: 30),
    )),
  ]);
}

Future getCurrentWeather() async {
  late Weather weather;
  // Paste your openWeatherAPI here (Below is an example link, it won't work in production)
  var url =
      "https://api.openweathermap.org/data/2.5/weather?lat=24.378&lon=88.6042&appid=d42cf05a53f6fd&units=metric";

  final response = await http.get(url);
  print(response.body);
  if (response.statusCode == 200) {
    weather = Weather.fromJSON(jsonDecode(response.body));
  }
  return weather;
}
