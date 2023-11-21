package com.example.navigationcodelab

import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.material.icons.filled.Build
import androidx.compose.material.icons.filled.Face
import androidx.compose.material.icons.filled.Person
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.vector.ImageVector

interface RallyDestination {
    val icon: ImageVector
    val route: String
    val screen: @Composable () -> Unit
}

//object用来声明类，在声明类的同时创建一个实例
object Account : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Add
    override val route: String = ""
    override val screen: @Composable () -> Unit = {}
}

object Overview : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Person
    override val route: String = "overview"
    override val screen: @Composable () -> Unit = { Overview }
}

object Bills : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Build
    override val route: String = "bills"
    override val screen: @Composable () -> Unit = {}
}

object SingleAccount : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Face
    override val route: String = "single_account"
    override val screen: @Composable () -> Unit = {}
}

val rallyTabRowScreens = listOf<RallyDestination>(Overview, Account, Bills)