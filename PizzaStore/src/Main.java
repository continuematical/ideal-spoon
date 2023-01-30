
public class Main {
    public static void main(String[] args) {
        PizzaStore store = new NYPizzaStore();
        store.orderPizza("cheese");
    }
}

abstract class PizzaStore {
    public void orderPizza(String type) {
        Pizza pizza = createPizza(type);
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
            return new NYStyleCheesePizza(new NYPizzaIngredientFactory());
        } else return null;
    }
}

class ChicagoStyleStore extends PizzaStore {
    @Override
    Pizza createPizza(String type) {
        if (type.equals("cheese")) {
            return new ChicagoStyleCheesePizza(new ChicagoPizzaIngredientFactory());
        } else return null;
    }
}

abstract class Pizza {
    String name;
    Dough dough;
    Sauce sauce;
    Cheese cheese;
    Veggies[] veggies;
    Pepperoni pepperoni;
    Clams clams;

    abstract void prepare();

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
    private PizzaIngredientFactory factory;

    public NYStyleCheesePizza(PizzaIngredientFactory factory) {
        this.factory = factory;
    }

    @Override
    void prepare() {
        name = "NY sauce and cheese pizza";
        dough = factory.createDough();
        cheese = factory.createCheese();
        clams = factory.createClams();
        pepperoni = factory.createPepperoni();
        sauce = factory.createSauce();
        veggies = factory.createVeggies();
    }
}

class ChicagoStyleCheesePizza extends Pizza {
    private PizzaIngredientFactory factory;

    @Override
    void prepare() {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = factory.createDough();
        cheese = factory.createCheese();
        clams = factory.createClams();
        pepperoni = factory.createPepperoni();
        sauce = factory.createSauce();
        veggies = factory.createVeggies();
    }

    public ChicagoStyleCheesePizza(PizzaIngredientFactory factory) {
        this.factory = factory;
    }

    @Override
    public void cut() {
        System.out.println("Cutting the pizza into square pieces");
    }
}

interface PizzaIngredientFactory {
    public Dough createDough();

    public Cheese createCheese();

    public Sauce createSauce();

    public Pepperoni createPepperoni();

    public Clams createClams();

    public Veggies[] createVeggies();
}

class NYPizzaIngredientFactory implements PizzaIngredientFactory {

    @Override
    public Dough createDough() {
        return new ThinCrustDough();
    }

    @Override
    public Cheese createCheese() {
        return new RegCheese();
    }

    @Override
    public Sauce createSauce() {
        return new MarinaraSauce();
    }

    @Override
    public Pepperoni createPepperoni() {
        return new SlicedPepperoni();
    }

    @Override
    public Clams createClams() {
        return new FreshClams();
    }

    @Override
    public Veggies[] createVeggies() {
        return new Veggies[]{new Garlic(), new Onion(), new Mushroom(), new RedPepper()};
    }
}

class ChicagoPizzaIngredientFactory implements PizzaIngredientFactory {

    @Override
    public Dough createDough() {
        return new ThickCrustDough();
    }

    @Override
    public Cheese createCheese() {
        return new RegCheese();
    }

    @Override
    public Sauce createSauce() {
        return new PlumTomatoSauce();
    }

    @Override
    public Pepperoni createPepperoni() {
        return new SlicedPepperoni();
    }

    @Override
    public Clams createClams() {
        return new FrozenClams();
    }

    @Override
    public Veggies[] createVeggies() {
        return new Veggies[]{new BlackOlive(), new Eggplant(), new Spinach(), new Mozzarella()};
    }
}

abstract class Dough {

}

class ThinCrustDough extends Dough {

}

class ThickCrustDough extends Dough {

}

abstract class Cheese {

}

class RegCheese extends Cheese {

}

abstract class Sauce {

}

class MarinaraSauce extends Sauce {

}

class PlumTomatoSauce extends Sauce {

}

abstract class Pepperoni {

}

class SlicedPepperoni extends Pepperoni {

}

abstract class Veggies {

}

abstract class Clams {

}

class FreshClams extends Clams {

}

class FrozenClams extends Clams {

}

//蔬菜类
class Garlic extends Veggies {

}

class Onion extends Veggies {

}

class Mushroom extends Veggies {

}

class RedPepper extends Veggies {

}

class Eggplant extends Veggies {

}

class Spinach extends Veggies {

}

class BlackOlive extends Veggies {

}

class Mozzarella extends Veggies {

}