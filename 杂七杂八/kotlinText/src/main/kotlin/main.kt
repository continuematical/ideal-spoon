fun main(args: Array<String>) {
    println("hello")
}

class Player {
    var name = "mary"
        get() = field.capitalize()
        set(value) {
            field = value.trim()
        }

    fun caseFireball(numFireball: Int = 2) = println("the number of Fireball is $numFireball")
}

class Dice {
    val rolledValue
        get() = (1..6).shuffled().first()
}