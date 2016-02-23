import java.util.Iterator;
import java.util.List;

public class FindGuitarTester {

	public static void main(String[] args) {
		Inventory inventory = new Inventory();
		initializeInventory(inventory);

		// GuitarSpec whatErinLikes = new GuitarSpec("", 0, Builder.FENDER,
		// "Stratocastor", Type.ELECTRIC, Wood.ALDER, Wood.ALDER);
		GuitarSpec whatErinLikes = new GuitarSpec(Builder.FENDER, "Stratocastor", Type.ELECTRIC, 12, Wood.ALDER,
				Wood.ALDER);

		List<Guitar> matchingGuitars = inventory.search(whatErinLikes);

		if (!matchingGuitars.isEmpty()) {

			for (Iterator<Guitar> i = matchingGuitars.iterator(); i.hasNext();) {
				Guitar guitar = i.next();
				GuitarSpec guitarSpec = guitar.getSpec();
				System.out.println("Erin, you might like this " + guitarSpec.getBuilder() + " " + guitarSpec.getModel()
						+ " " + guitarSpec.getType() + " guitar:\n   " + guitarSpec.getBackWood()
						+ " back and sides, \n   " + guitarSpec.getTopWood() + " top. \nYou can have it for only $"
						+ guitar.getPrice() + "!");

			}
		}

		else {
			System.out.println("Sorry, Erin, we have nothing for you");
		}
	}

	private static void initializeInventory(Inventory inventory) {
		GuitarSpec spec = new GuitarSpec(Builder.FENDER, "Stratocastor", Type.ELECTRIC, 12, Wood.ALDER, Wood.ALDER);
		inventory.addGuitar("V95693", 1499.96, spec);
		spec = new GuitarSpec(Builder.FENDER, "Stratocastor", Type.ELECTRIC, 12, Wood.ALDER, Wood.ALDER);
		// inventory.addGuitar("V95693", 1499.96, Builder.FENDER,
		// "Stratocastor", Type.ELECTRIC, Wood.ALDER, Wood.ALDER);
		inventory.addGuitar("V9512", 1549.95, spec);

	}
}
