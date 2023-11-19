package com.example.navigationcodelab

import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.vector.ImageVector

interface RallyDestination {
    val icon: ImageVector
    val route: String
    val screen: @Composable () -> Unit
}

object Account : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Add
    override val route: String = ""
    override val screen: @Composable () -> Unit
        get() = TODO("Not yet implemented")
}