import java.util.Scanner;

class Default{
	
	void displayDef() {
		System.out.println("This is a Default Access Modifier");
	}
}

class Public{
	
	public void displayPub() {
		System.out.println("This is a Public Access Modifier");
	}
	
}

class Private{
	
	private int num =100;
	
	private void displayPriv() {
		System.out.println("This is a Private Access Modifier " +num);
	}
	
}



class Protected{
	
	protected void displayPro(){
		System.out.println("This is a Protected Access Modifier ");
	}
	
}

class A extends Protected {}
class B extends A {}



public class modifiers {

	public static void main(String[] args) {
		
		try {
		
			//Default Access Modifier
			Default obj = new Default();
			obj.displayDef();
			
			//Public Access Modifier
			Public pub = new Public();
			pub.displayPub();
			
			//Private Access Modifier
			Private priv = new Private();
//			priv.displayPriv();  		
	//		--------------> COMPILE TIME ERROR
			
			
			//Protected Access Modifier
			Protected protec = new Protected();
	//		A AObj = new A();
	//		AObj.displayPro();
			
			B bObj = new B();
			bObj.displayPro();
		}
		catch(Exception e) {
			System.out.println("Retry");
		}

	}

}
