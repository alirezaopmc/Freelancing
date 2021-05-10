package old;

public class Main {

    public static int line_progression(int n, int a, int b) {
        return a * n + b;
    }

    public static int sum_with_iter(int n, int a, int b) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += line_progression(i, a, b);
        }
        return sum;
    }

    public static int sum_with_formula(int n, int a, int b) {
        int coefficient_of_a = n * (n+1) / 2;
        int coefficient_of_b = n;
        return coefficient_of_a * a + coefficient_of_b * b;
    }

    public static boolean isPrime(int n) {

        for(int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;

//        if (n == 2) return true;
//        if (n % 2 == 0) return false;
//        for(int i = 3; i * i <= n; i+=2) {
//            if (n % i == 0) return false;
//            // i is a divisor of n except 1 and n, so n is prime
//        }
//        return true;
    }

    public static void main(String[] args) {

        // Basic
        // Data type - Java is type-safe

        // Primitive
        int number = 213;
        float pi = 3.14f;
        double golden_rate = 2.7;
        boolean b = true;
        boolean bb = 3 > 1;
        char c = 'A';
        char n = '\n';
        char tab = '\t';
        byte byt; // ?

        // Advanced
        String str = "My name is alireza";
        // Own CLass (e.g. old.Chest)
        // StringBuilder

        // Assignment
        // LValue = RValue
        //  LValue: A reference to an object in memory
        //  RValue: A reference to another object or a value
        //      =1. Ref => Class (Excluding String)
        //      =2. Val => Integer & Float
        Chest chest = new Chest(21);
        Chest chest2 = chest;
        System.out.println(chest.capacity + " " + chest2.capacity);
        chest.capacity = 200;
        System.out.println(chest.capacity + " " + chest2.capacity);

        // 2
        int age = 20;
        int another_int = age;
        System.out.println(age + " " + another_int);
        age = 21;
        System.out.println(age + " " + another_int);


        // old.Main Structures
        // 0. Scopes
        // [Manager] { Scope Body }
        // public static void main(String args[]) {
        //      // Scope Body
        // }

        // 1. Condition
        // Boolean Algebra
        // {0 ,1} \ {True, False}
        // a = True, b = False
        // a or b = at least one is true
        boolean expression = (13 < 21) && (2 * 6 - 12 == 10);
//        boolean running = (turn < 60) && (winner != 0);
//        winner = 1 => A
//        winner = 2 => B
//        winner = 0 => No Winner yet
//        winner = 3 => Draw
        if (expression && true && !false || true) {
            System.out.println("The conditions are met.");
        }


//        if (condition : boolean algebra expression) { some actions }


        // 2. Loop
        // for(int i = 0; ...) { some action }
        for(int i = 0; i < 100; i++) {
            int temp = 2 * i + 3;
        }

        System.out.println("In the do scope");
        while(true) {
            System.out.println("In the do scope");
            break;
        }

        do {
            System.out.println("In the do scope");
            break;
        } while (true);

        // 3. Structures (Functions and Classes)
        System.out.println(isPrime(13));
//        show_n_linear_prg(5, 2, 3);
        System.out.println(sum_with_iter(2, 2, 3) == sum_with_formula(2, 2, 3));
    }
}
