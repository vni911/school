package earth;

class Human {
    private String name;

    Human(String name) {
        this.name = name;
    }

    String getName() {
        return name;
    }
}

class Alien {
    private String name;
    private static Human humanName;

    Alien(String name) {
        this.name = name;
    }

    void letMeKnowYourName(Human h) {
        humanName = h;
    }

    void tellHumanName() {
        System.out.println("I'm alien, " + name + ". Human name is " + humanName.getName());
    }
}

public class earth {
    public static void main(String[] args) {
        Human tom = new Human("Tom");
        Alien alien1 = new Alien("PPUPPU");
        Alien alien2 = new Alien("PPAPPA");
        alien1.letMeKnowYourName(tom);
        alien2.tellHumanName();
        alien1.tellHumanName();
    }
}

