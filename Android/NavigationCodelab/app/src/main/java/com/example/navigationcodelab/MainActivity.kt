package com.example.navigationcodelab

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Scaffold
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import com.example.navigationcodelab.ui.theme.RallyTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            RallyApp()
        }
    }
}

//@Composable
//fun Greeting(name: String, modifier: Modifier = Modifier) {
//    Text(
//        text = "Hello $name!",
//        modifier = modifier
//    )
//}
//
//@Preview(showBackground = true)
//@Composable
//fun GreetingPreview() {
//    NavigationCodelabTheme {
//        Greeting("Android")
//    }
//}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun RallyApp() {
    RallyTheme {
        val currentScreen: RallyDestination by remember { mutableStateOf(Overview) }
        Scaffold(
            topBar = {

            }
        ) { innerPadding ->
            Box(modifier = Modifier.padding(innerPadding)) {
                currentScreen.screen()
            }
        }
    }
}