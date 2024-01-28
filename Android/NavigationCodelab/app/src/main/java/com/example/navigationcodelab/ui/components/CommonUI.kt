package com.example.navigationcodelab.ui.components

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.KeyboardArrowRight
import androidx.compose.material3.Divider
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.semantics.clearAndSetSemantics
import androidx.compose.ui.semantics.contentDescription
import androidx.compose.ui.unit.dp
import com.example.navigationcodelab.R
import java.text.DecimalFormat


private val AccountDecimalFormat = DecimalFormat("###")
private val AmountDecimalFormat = DecimalFormat("#,###.##")

fun formatAmount(amount: Float): String {
    return AmountDecimalFormat.format(amount)
}


@Composable
private fun BaseRow(
    modifier: Modifier = Modifier,
    color: Color,
    title: String,
    subtitle: String,
    amount: Float,
    negative: Boolean
) {
    Row(
        modifier = modifier
            .height(68.dp)
            .clearAndSetSemantics {
                contentDescription =
                    "$title account ending in ${subtitle.takeLast(4)}"
            },
        verticalAlignment = Alignment.CenterVertically
    ) {
        val dollarSign = if (negative) "-$" else "$"
        val formattedAmount = formatAmount(amount)
        val typography = MaterialTheme.typography
        AccountIndicator(color = color, modifier = modifier)
        Spacer(modifier = Modifier.width(12.dp))
        Column(Modifier) {
            Text(
                text = title,
                style = typography.bodyLarge
            )
            Text(text = subtitle, style = typography.bodySmall)
        }
        Spacer(modifier = Modifier.weight(1f))
        Row(
            horizontalArrangement = Arrangement.SpaceBetween
        ) {
            Text(
                text = dollarSign,
                style = typography.bodySmall,
                modifier = modifier.align(Alignment.CenterVertically)
            )
            Text(
                text = formattedAmount,
                style = typography.bodySmall,
                modifier = modifier.align(Alignment.CenterVertically)
            )
        }
        Spacer(modifier = Modifier.width(16.dp))
        Icon(
            imageVector = Icons.Filled.KeyboardArrowRight,
            contentDescription = null,
            modifier = Modifier
                .padding(end = 12.dp)
                .size(24.dp)
        )
    }
    RallyDivider()
}

@Composable
fun RallyDivider(modifier: Modifier = Modifier) {
    Divider(color = MaterialTheme.colorScheme.background, thickness = 1.dp)
}


@Composable
private fun AccountIndicator(color: Color, modifier: Modifier = Modifier) {
    Spacer(
        modifier = Modifier
            .size(4.dp, 36.dp)
            .background(color = color)
    )
}

@Composable
fun AccountRow(
    modifier: Modifier = Modifier,
    name: String,
    number: Int,
    amount: Float,
    color: Color
) {
    BaseRow(
        modifier = modifier,
        color = color,
        title = name,
        subtitle = stringResource(R.string.account_redacted) + AccountDecimalFormat.format(number),
        amount = amount, negative = false
    )
}

@Composable
fun BillRow(
    color: Color,
    name: String,
    due: String,
    amount: Float
) {
    BaseRow(
        color = color,
        title = name,
        subtitle = "Due $due",
        amount = amount,
        negative = true
    )
}