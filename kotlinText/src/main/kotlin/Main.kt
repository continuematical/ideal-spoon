import java.io.File
import java.lang.Exception
import java.lang.IllegalStateException
import kotlin.math.roundToInt

//文件级变量
const val MAX_EXPERIENCE = 20;

fun main(args: Array<String>) {

    performPurchase(10.7)
    //匿名函数
    //任何不需要参数且能返回String的函数都可以赋值给greetingFunction

    //无参数
    val greetingFunction1: () -> String = {
        val currentYear = 2008
        "welcome to the current year $currentYear"
        //匿名函数会隐式或自动返回函数体最后一行语句的结果
    }

    //有参数
    val greetingFunction2: (String) -> String = { playerName ->
        val currentYear = 2008
        "welcome $playerName to the current year $currentYear"
    }

    //it代替单个参数
    val greetingFunction3: (String) -> String = { it ->
        val currentYear = 2008
        "welcome $it to the current year $currentYear"
    }

    //多个参数
    val greetingFunction4: (String, Int) -> String = { playerName, currentYear ->
        "welcome $playerName to the current year $currentYear"
    }

    val greetingFunction5: (String, Int) -> String = { playerName, numBuildings ->
        "add buildings $numBuildings , welcome $playerName"
    }

    //类型推断
    val greetingFunction6 = {
        val currentYear = 2008
        "welcome to the current year $currentYear"
    }

    val greetingFunction7 = { playerName: String, numBuildings: Int ->
        "add buildings $numBuildings , welcome $playerName"
    }

    println(greetingFunction1())
    //获得函数引用
    runSimulation1("Tom", ::printConstructCost, greetingFunction4)
}

fun readBeverage() {
    //let操作符：it 隐式返回函数结果
    var beverage1 = readLine()?.let {
        if (it.isNotBlank()) {
            it.capitalize()
        } else {
            "Buttered Ale"
        }
    }
    //!!.
    var beverage2 = readLine()!!.capitalize()

    //if else
    var beverage3 = readLine();
    if (beverage3 != null) {
        var capitalize = beverage3.capitalize()
    } else {
        println("I can't do that without crashing - beverage was null!")
    }

    //空合并操作符
    var beverage4: String = beverage3 ?: "Buttered Ale"

    //总结
    var beverage5 = readLine();
    beverage5?.let {
        beverage5 = it.capitalize()
    } ?: println("BUttered Ale")
}

//可见性修饰符    函数名             函数参数
private fun formatHealthStatus(healthPoints: Int, isBlessed: Boolean) =
    when (healthPoints) {
        100 -> "is in excellent condition"
        in 90..99 -> "has a few scratches."
        in 75..89 -> if (isBlessed) {
            "has some minor wounds ,but is healing quite quickly"
        } else {
            "has some minor wounds"
        }

        in 15..74 -> "look pretty hurt"
        else -> "is in awful conditions"
    }

private fun printPlayerStatus(
    auraColor: String,
    isBlessed: Boolean,
    name: String,
    healthStatus: String
) {
    println("(Aura: $auraColor) " + "(Blessed: ${if (isBlessed) "YES" else "NO"})")
    println("$name $healthStatus")
}

private fun auraColor(
    isBlessed: Boolean,
    healthPoints: Int,
    isImmortal: Boolean
) = if (isBlessed && healthPoints > 50 || isImmortal) "GREEN" else "NOME"

//默认值参数，单表达式
private fun caseFireball(numFireball: Int = 2) =
    println("A glass of Fireball springs into existence.(x$numFireball)")
//返回值为Unit

private fun showFireballPoint(numFireball: Int) =
    when (numFireball) {
        in 1..10 -> "tipsy"
        in 11..20 -> "sloshed"
        in 21..30 -> "soused"
        in 31..40 -> "stewed"
        else -> "..t0aSt3d"
    }

//定义的lambda会以对象的形式存在，JVM会为所有通lambda打交道的变量分配内存，这就产生了内存开销
//函数引用
inline fun runSimulation1(playerName: String, costPrinter: (Int) -> Unit, greetingFunction: (String, Int) -> String) {
    //产生1-3之间的随机数
    val numBuildings = (1..3).shuffled().last()
    costPrinter(numBuildings)
    println(greetingFunction(playerName, numBuildings))
}

fun printConstructCost(numBuildings: Int) {
    val cost = 500
    println("construction cost:${cost * numBuildings}")
}

//函数作为返回类型
fun runSimulation2() {
    val configureGreetingFunction = configureGreetingFunction()
    println(configureGreetingFunction("Goggle"))
}

fun configureGreetingFunction(): (String) -> String {
    val structureType = "hospitals"
    var numBuildings = 5
    return { playerName: String ->
        val currentYear = 2018
        numBuildings += 1
        println("add $numBuildings $structureType")
        "welcome to village , $playerName!( copyright $currentYear)"
    }
}

//自定义异常
class UnskilledSwordJugglerException : IllegalStateException("player can not juggle swords")

const val TAVERN_NAME = "Tavern's Folly"

//字符串
private fun placeOrder(patronName: String, menuData: String) {
    val indexOfApostrophe = TAVERN_NAME.indexOf('\'')
    val tavernMaster = TAVERN_NAME.substring(0 until indexOfApostrophe)
    println("Madrigal speaks with $tavernMaster about their order.")

//    val data = menuData.split(',')
//    val type = data[0]
//    val name = data[1]
//    val price = data[2]

    //List支持解构的语法特性
    val (type, name, price) = menuData.split(',')
    //val message = "Madrigal buys a $name ($type) for $price."
    val message = "$patronName buys a $name($type) for $price"
    println(message)

    performPurchase()

    val phrase = if (name == "Dragon's Breath") {
        "Madrigal exclaims ${toDragonSpeak("Ah,delicious $name")}"
    } else {
        "Madrigal says: Thanks for the $name"
    }
}

private fun toDragonSpeak(phrase: String) =
    phrase.replace(Regex("[aeiou]")) {
        when (it.value) {
            "a" -> "4"
            "e" -> "3"
            "i" -> "1"
            "o" -> "0"
            "u" -> "|_|"
            else -> it.value
        }
    }

fun performPurchase() {
    displayBalance()
}

fun performPurchase(price: Double) {
    displayBalance()
    val totalPurse = playerGold + (playerSilver / 100.0)
    println("Total purse: $totalPurse")
    println("Purchasing item for $price")

    val remainingBalance = totalPurse - price
    //格式类型化
    println("Remaining balance: ${"%.2f".format(remainingBalance)}")

    val remainingGold = remainingBalance.toInt()
    val remainingSilver = (remainingBalance % 1 * 100).roundToInt()
    playerGold = remainingGold
    playerSilver = remainingSilver
    displayBalance()
}

var playerGold = 10;
var playerSilver = 10;

fun displayBalance() {
    println("Player's purse balance: Gold : $playerGold , Silver: $playerSilver")
}

//标准库函数
//apply
val menuFile = File("menu-file.txt").apply {
    setReadable(true)
    setWritable(true)
    setExecutable(true)
    //相关作用域，针对接受者的隐式调用
}

//let
val firstElement = listOf(1, 2, 3).first().let {
    it * it
}

fun formatGreeting(VIPGuest: String?): String {
    return VIPGuest?.let {
        "Welcome , $it. Please go straight back - your table is ready."
    } ?: "Welcome to the tavern. You will be seated soon."
}

//接收值：apply不传递，let传递接收者
//返回值：apply返回当前接收者。let返回lambda最后一行

//run
//和apply差不多，run函数不返回接收者，返回lambda最后一行的结果
//val serveDragonsBreathe = File("menu-file.txt").run {
//    readText().contains("Dragon's Breath")
//}
