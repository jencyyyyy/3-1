package com.example.colormyviews

import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.TextView
import android.widget.Button
import androidx.constraintlayout.widget.ConstraintLayout


class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        setListeners()
    }

    private fun setListeners() {
        var box_text_one: TextView = findViewById(R.id.box_one_text)
        var box_text_two: TextView = findViewById(R.id.box_two_text)
        var box_text_three: TextView = findViewById(R.id.box_three_text)
        var box_text_four: TextView = findViewById(R.id.box_four_text)
        var box_text_five: TextView = findViewById(R.id.box_five_text)
        var red_button: Button = findViewById(R.id.red_button)
        var green_button: Button = findViewById(R.id.green_button)
        var yellow_button: Button = findViewById(R.id.yellow_button)
        var constraint_layout:ConstraintLayout = findViewById(R.id.constraint_layout)


        val clickableViews: List<View> =
            listOf(box_text_one, box_text_two, box_text_three,
                box_text_four, box_text_five,
                red_button, green_button,yellow_button,constraint_layout )


        for (item in clickableViews) {
            item.setOnClickListener { makeColored(it) }
        }
    }

    private fun makeColored(view: View) {
        var box_text_three: TextView = findViewById(R.id.box_three_text)
        var box_text_four: TextView = findViewById(R.id.box_four_text)
        var box_text_five: TextView = findViewById(R.id.box_five_text)
        when (view.id) {


            R.id.box_one_text -> view.setBackgroundColor(Color.DKGRAY)
            R.id.box_two_text -> view.setBackgroundColor(Color.GRAY)

            R.id.box_three_text -> view.setBackgroundResource(android.R.color.holo_green_light)
            R.id.box_four_text -> view.setBackgroundResource(android.R.color.holo_green_dark)
            R.id.box_five_text -> view.setBackgroundResource(android.R.color.holo_green_light)

            R.id.red_button -> box_text_three.setBackgroundResource(R.color.my_red)
            R.id.yellow_button -> box_text_four.setBackgroundResource(R.color.my_yellow)
            R.id.green_button -> box_text_five.setBackgroundResource(R.color.my_green)

            else -> view.setBackgroundColor(Color.LTGRAY)
        }
    }


}