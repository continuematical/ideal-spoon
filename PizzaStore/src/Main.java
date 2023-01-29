import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        PizzaStore store = new NYPizzaStore();
        store.orderPizza("cheese");
    }
}

abstract class PizzaStore {
    public void orderPizza(String type) {
        Pizza pizza = new Pizza();
        pizza = createPizza(type);
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
    }

    abstract Pizza createPizza(String type);
}

class NYPizzaStore extends PizzaStore {
    @Override
    Pizza createPizza(String type) {
        if (type.equals("cheese")) {
            return new NYStyleCheesePizza();
        } else return null;
    }
}

class ChicagoStyleStore extends PizzaStore {
    @Override
    Pizza createPizza(String type) {
        if (type.equals("cheese")) {
            return new ChicagoStyleCheesePizza();
        } else return null;
    }
}

class Pizza {
    String name;
    String dough;
    String sauce;
    ArrayList<String> topping = new ArrayList<>();

    public void prepare() {
        System.out.println("Preparing" + name);
        System.out.println("Tossing dough");
        System.out.println("Adding sauce");
        for (int i = 0; i < topping.size(); i++) {
            System.out.println(topping.get(i));
        }
    }

    public void bake() {
        System.out.println("Baking for 45 minutes at 350");
    }

    public void cut() {
        System.out.println("Cutting the pizza into diagonal pieces");
    }

    public void box() {
        System.out.println("Please place the pizza into official PizzaStore box");
    }
}

class NYStyleCheesePizza extends Pizza {
    public NYStyleCheesePizza() {
        name = "NY sauce and cheese pizza";
        dough = "thin crust dough";
        sauce = "Marinara Sauce";

        topping.add("Grated cheese");
    }
}

class ChicagoStyleCheesePizza extends Pizza {
    public ChicagoStyleCheesePizza() {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra thick crust dough";
        sauce = "Plum tomato sauce";

        topping.add("Shredded Mozzarella Cheese");
    }

    @Override
    public void cut() {
        System.out.println("Cutting the pizza into square pieces");
    }
}