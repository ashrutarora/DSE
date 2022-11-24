import java.util.Scanner;

interface sports {

    void getNumberofGoals();
    void dispTeam();
}

class Hockey implements sports {
    int ng;
    String arr[];

    Hockey(int ng, String arr[]) {
        this.ng = ng;
        this.arr = arr;
    }

    public void getNumberofGoals() {
        System.out.println("Number of goals is: " + ng);
    }

    public void dispTeam() {
        int n = arr.length, i;

        System.out.println("Team members are: ");
        for (i = 0; i < n; i++)
            System.out.println(arr[i]);
    }
}

class Football implements sports {
    int ng;
    String arr[];

    Football(int ng, String arr[]) {
        this.ng = ng;
        this.arr = arr;
    }

    public void getNumberofGoals() {
        System.out.println("Number of goals is: " + ng);
    }

    public void dispTeam() {
        int n = arr.length, i;

        System.out.println("Team members are: ");
        for (i = 0; i < n; i++)
            System.out.println(arr[i]);
    }
}

public class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int ng, i, n, ng1, n1;
        try {
            System.out.println("Enter the number of goals scored in Hockey: ");
            ng = sc.nextInt();

            System.out.println("Enter the number of team members of the Hockey Team: ");
            n = sc.nextInt();

            String arr[] = new String[n];

            System.out.println("Enter the team members of the Hockey Team: ");
            for (i = 0; i < n; i++)
                arr[i] = sc.next();

            Hockey h = new Hockey(ng, arr);
            h.getNumberofGoals();
            h.dispTeam();

            System.out.println("Enter the number of goals scored in Football: ");
            ng1 = sc.nextInt();

            System.out.println("Enter the number of team members of the Football Team: ");
            n1 = sc.nextInt();

            String arr1[] = new String[n1];

            System.out.println("Enter the team members of the Football Team: ");
            for (i = 0; i < n1; i++)
                arr1[i] = sc.next();

            Football f = new Football(ng1, arr1);
            f.getNumberofGoals();
            f.dispTeam();

        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
}