import androidx.compose.runtime.Immutable
import androidx.compose.ui.graphics.Color

@Immutable
data class Account(
    val name: String,
    val color: Color,
    val balance: Float,
    val number: Int
)

@Immutable
data class Bill(
    val name: String,
    val due: String,
    val amount: Float,
    val color: Color
)

object UserData {

    val bills: List<Bill> = listOf(
        Bill(
            "RedPay Credit",
            "Jan 29",
            45.36f,
            Color(0xFFFFDC78)
        ),
        Bill(
            "Rent",
            "Feb 9",
            1200f,
            Color(0xFFFF6951)
        ),
        Bill(
            "TabFine Credit",
            "Feb 22",
            87.33f,
            Color(0xFFFFD7D0)
        ),
        Bill(
            "ABC Loans",
            "Feb 29",
            400f,
            Color(0xFFFFAC12)
        ),
        Bill(
            "ABC Loans 2",
            "Feb 29",
            77.4f,
            Color(0xFFFFAC12)
        )
    )

    val accounts: List<Account> = listOf(
        Account(
            "checking",
            Color(0xff004940),
            2215.13f,
            1234
        ),
        Account(
            "Home Savings",
            Color(0xff005d57),
            8676.88f,
            5678
        ),
        Account(
            "Car Savings",
            Color(0xff04b97f),
            987.48f,
            9012
        ),
        Account(
            "vacation",
            Color(0xff37efba),
            253f,
            5678
        )
    )

    fun getAccount(accountName: String?): Account {
        return accounts.first { it.name == accountName }
    }
}