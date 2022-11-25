import java.util.Scanner;

class Game{

	void type(){
		System.out.println("Indoor and Outdoor Games");
	}
}

class Cricket extends Game{

	void type(){
		System.out.println("Cricket is an Outdoor Game");
	}
}

class Chess extends Game{

	void type(){
		System.out.println("Chess is an Indoor Game");
	}
}


public class P4 {

	public static void main(String[] args) {
		
		Game game = new Game();
		Cricket cricket = new Cricket();
		Chess chess = new Chess();

		game.type();
		cricket.type();
		chess.type();

	}

}
