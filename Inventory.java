import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Inventory {

	private List<Guitar> guitars;

	Inventory() {
		guitars = new LinkedList<Guitar>();
	}

	public void addGuitar(String SerialNumber, double price, GuitarSpec guitarSpec) {
		Guitar guitar = new Guitar(SerialNumber, price, guitarSpec);
		guitars.add(guitar);
	}

	public Guitar getGuitar(String serialNumber) {
		for (Iterator<Guitar> i = guitars.iterator(); i.hasNext();) {
			Guitar guitar = i.next();
			if (guitar.getSerialNumber().equals(serialNumber))
				return guitar;
		}
		return null;
	}

	public List<Guitar> search(GuitarSpec searchSpec) {

		List<Guitar> matchingGuitars = new LinkedList<Guitar>();

		for (Iterator<Guitar> i = guitars.iterator(); i.hasNext();) {
			Guitar guitar = i.next();

			GuitarSpec guitarSpec = guitar.getSpec();

			if (searchSpec.matches(guitarSpec))
				matchingGuitars.add(guitar);
		}

		return matchingGuitars;
	}
}
