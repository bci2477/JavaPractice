
public class Guitar {

	private String serialNumber;
	private double price;
	private GuitarSpec spec;

	public Guitar(String serialNumber, double price, GuitarSpec spec) {
		this.serialNumber = serialNumber;
		this.price = price;
		this.spec = spec;
		// spec = new GuitarSpec(builder, model, type, backWood, topWood);
	}

	public String getSerialNumber() {
		return serialNumber;
	}

	public double getPrice() {
		return price;
	}

	public GuitarSpec getSpec() {
		return spec;
	}

	public void setSerialNumber(String serialNumber) {
		this.serialNumber = serialNumber;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public void setSpec(GuitarSpec spec) {
		this.spec = spec;
	}

}
