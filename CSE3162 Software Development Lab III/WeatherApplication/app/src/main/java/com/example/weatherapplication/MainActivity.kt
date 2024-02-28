package com.example.weatherapplication

import android.graphics.Color
import android.os.AsyncTask
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.*
import androidx.appcompat.app.AppCompatActivity
import androidx.constraintlayout.widget.ConstraintLayout

import com.bumptech.glide.Glide
import org.json.JSONObject
import java.net.URL

class MainActivity : AppCompatActivity() {
    var city: String = "Dhaka"
 //   val api: String = "6cef81bed8d8415da1f150956222311"


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        weatherTask().execute()

        val inputLoc = findViewById<Button>(R.id.searchButton)

        inputLoc.setOnClickListener{
            getLoc();
            weatherTask().execute()
        }

    }

    inner class weatherTask(): AsyncTask<String, Void, String>(){

        override fun doInBackground(vararg params: String?): String? {
            var reply: String?
            try {
                reply = //https://api.weatherapi.com/v1/forecast.json?key=6cef81bed8d8415da1f150956222311&q=$city&days=2
                    URL("https://api.weatherapi.com/v1/forecast.json?key=6cef81bed8d8415da1f150956222311&q=$city&days=8").readText( Charsets.UTF_8)
            }catch (e : Exception){ //https://api.weatherapi.com/v1/current.json?key=6cef81bed8d8415da1f150956222311&q=$city
                reply =null
            }
            return reply
        }//To get 7 day weather for US Zipcode 07112: JSON: http://api.weatherapi.com/v1/forecast.json?key=<YOUR_API_KEY>&q=07112&days=7

        override fun onPostExecute(reply: String?) {
            super.onPostExecute(reply)
            try {
                val getJSONObjectFiles = JSONObject(reply);
                val current = getJSONObjectFiles.getJSONObject("current")
                val temperatureC = current.getString("temp_c")
                val lastupdate = current.getString("last_updated")
                val loc = this@MainActivity.city //current.getString("name") //
                val weatherCondition = current.getJSONObject("condition")
                val conditionText = weatherCondition.getString("text")
                val conditionImage = weatherCondition.getString("icon")

               // Log.d("Maiinimg", conditionImage)

                var imageView =  findViewById<ImageView>(R.id.iconForWeather)
                var url = "https:"+conditionImage

                Glide.with(this@MainActivity)
                    .load(url)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView)

                findViewById<TextView>(R.id.showTemperatureView).text = "Today: "+ temperatureC + "°C"
                findViewById<TextView>(R.id.lastUpdated).text = lastupdate

                findViewById<TextView>(R.id.location).text = loc
                findViewById<TextView>(R.id.ConditionForWeatherView).text = conditionText;

                changeBG(temperatureC)

                //----------------------------------------------------------------------------------

                val Forcast = getJSONObjectFiles.getJSONObject("forecast")
                val Futurearray   = Forcast.getJSONArray("forecastday")


//-----------------------------------------------------------------------------------------------
                //Index-1 data-0
                val jsonObject: JSONObject = Futurearray.getJSONObject(1)
           //     Log.d("infof", jsonObject.toString())
                val date0 = jsonObject.getString("date")

           //     Log.d("infoff",date0)
                val day0 = jsonObject.getJSONObject("day")
                val avgtemp_c0 = day0.getString("avgtemp_c")
           //     Log.d("ave",avgtemp_c0)
                findViewById<TextView>(R.id.day0).text = date0
                findViewById<TextView>(R.id.type0).text = avgtemp_c0+ "°C"
                val day0Condition = day0.getJSONObject("condition")


                val conditionImageday0 = day0Condition.getString("icon")


                val imageView0=  findViewById<ImageView>(R.id.imageView0)
                val url0 = "https:"+conditionImageday0

                Glide.with(this@MainActivity)
                    .load(url0)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView0)

//-----------------------------------------------------------------------------------------------
                //Index-2 data-1

                val jsonObject1: JSONObject = Futurearray.getJSONObject(2)
                val date1 = jsonObject1.getString("date")
                val day1 = jsonObject1.getJSONObject("day")
                val avgtemp_c1 = day1.getString("avgtemp_c")
                val day1Condition = day1.getJSONObject("condition")
                val conditionImageday1 = day1Condition.getString("icon")

                findViewById<TextView>(R.id.day1).text = date1
                findViewById<TextView>(R.id.type1).text = avgtemp_c1+ "°C"
                val imageView1 =  findViewById<ImageView>(R.id.imageView1)
                val url1 = "https:"+conditionImageday1

                Glide.with(this@MainActivity)
                    .load(url1)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView1)

//-----------------------------------------------------------------------------------------------

                //Index-3 data-2

                val jsonObject2: JSONObject = Futurearray.getJSONObject(3)
                val date2 = jsonObject2.getString("date")
                val day2 = jsonObject2.getJSONObject("day")
                val avgtemp_c2 = day2.getString("avgtemp_c")
                val day2Condition = day2.getJSONObject("condition")
                val conditionImageday2 = day2Condition.getString("icon")

                findViewById<TextView>(R.id.day2).text = date2
                findViewById<TextView>(R.id.type2).text = avgtemp_c2+ "°C"
                val imageView2 =  findViewById<ImageView>(R.id.imageView2)
                val url2 = "https:"+conditionImageday2

                Glide.with(this@MainActivity)
                    .load(url2)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView2)

//-----------------------------------------------------------------------------------------------

                //Index-4 data-3

                val jsonObject3: JSONObject = Futurearray.getJSONObject(4)
                val date3 = jsonObject3.getString("date")
                val day3 = jsonObject3.getJSONObject("day")
                val avgtemp_c3 = day3.getString("avgtemp_c")
                val day3Condition = day3.getJSONObject("condition")
                val conditionImageday3 = day3Condition.getString("icon")

                findViewById<TextView>(R.id.day3).text = date3
                findViewById<TextView>(R.id.type3).text = avgtemp_c3+ "°C"
                val imageView3 =  findViewById<ImageView>(R.id.imageView3)
                val url3 = "https:"+conditionImageday3

                Glide.with(this@MainActivity)
                    .load(url3)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView3)

//-----------------------------------------------------------------------------------------------

                //Index-5 data-4

                val jsonObject4: JSONObject = Futurearray.getJSONObject(5)
                val date4 = jsonObject4.getString("date")
                val day4 = jsonObject4.getJSONObject("day")
                val avgtemp_c4 = day4.getString("avgtemp_c")
                val day4Condition = day4.getJSONObject("condition")
                val conditionImageday4 = day4Condition.getString("icon")

                findViewById<TextView>(R.id.day4).text = date4
                findViewById<TextView>(R.id.type4).text = avgtemp_c4+ "°C"
                val imageView4 =  findViewById<ImageView>(R.id.imageView4)
                val url4 = "https:"+conditionImageday4

                Glide.with(this@MainActivity)
                    .load(url4)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView4)

//-----------------------------------------------------------------------------------------------

                //Index-6 data-5

                val jsonObject5: JSONObject = Futurearray.getJSONObject(6)
                val date5 = jsonObject5.getString("date")
                val day5 = jsonObject5.getJSONObject("day")
                val avgtemp_c5 = day5.getString("avgtemp_c")
                val day5Condition = day5.getJSONObject("condition")
                val conditionImageday5 = day5Condition.getString("icon")

                findViewById<TextView>(R.id.day5).text = date5
                findViewById<TextView>(R.id.type5).text = avgtemp_c5+ "°C"
                val imageView5 =  findViewById<ImageView>(R.id.imageView5)
                val url5 = "https:"+conditionImageday5

                Glide.with(this@MainActivity)
                    .load(url5)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView5)
//-----------------------------------------------------------------------------------------------

                //Index-7 data-6

                val jsonObject6: JSONObject = Futurearray.getJSONObject(7)
                val date6 = jsonObject6.getString("date")
                val day6 = jsonObject6.getJSONObject("day")
                val avgtemp_c6 = day6.getString("avgtemp_c")
                val day6Condition = day6.getJSONObject("condition")
                val conditionImageday6 = day6Condition.getString("icon")

                findViewById<TextView>(R.id.day6).text = date6
                findViewById<TextView>(R.id.type6).text = avgtemp_c6+ "°C"
                val imageView6=  findViewById<ImageView>(R.id.imageView6)
                val url6 = "https:"+conditionImageday6

                Glide.with(this@MainActivity)
                    .load(url6)
                    .error(com.google.android.material.R.drawable.mtrl_ic_error)
                    .into(imageView6)

//-----------------------------------------------------------------------------------------------

                findViewById<ProgressBar>(R.id.progressBar).visibility = View.GONE
                findViewById<ConstraintLayout>(R.id.activityMainView).visibility = View.VISIBLE
                findViewById<TextView>(R.id.MessageError).visibility = View.GONE

            }
            catch(error:Exception){
                findViewById<ProgressBar>(R.id.progressBar).visibility = View.GONE
                findViewById<TextView>(R.id.MessageError).visibility = View.VISIBLE
            }
        }
    }

    fun getLoc(){
        val locationtyped = findViewById<EditText>(R.id.enterLocation);
        city = locationtyped.text.toString();
    }

    //----------------------------------------------------------------------------------
    // Change the background with respect to the change of "temperatureC"
    //get the main Container
    //  container <ConstraintLayout>  = findLayoutId(R.id.activityMainView)
    fun changeBG(temperatureC: String) {
       // val c : Constraintlayout  = findViewById(R.id.activityMainView)

        var c = findViewById<ConstraintLayout>(R.id.activityMainView)

        if(temperatureC < "0.0")
        {
             c.setBackgroundColor(Color.parseColor("#062b75" ))

        }else if ((temperatureC > "0.0") && (temperatureC < "10.0"))
        {
            c.setBackgroundColor(Color.parseColor("#8daff5" ))
        }
        else if((temperatureC > "10.0") && (temperatureC< "25.0"))
        {
            c.setBackgroundColor(Color.GREEN)
        }
        else if ((temperatureC > "25.0") && (temperatureC< "35.0"))
        {
            c.setBackgroundColor(Color.YELLOW)
        }
        else if ((temperatureC > "35.0") && (temperatureC <"45.0"))
        {
            c.setBackgroundColor(Color.RED)
        }

    }

}