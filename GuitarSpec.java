
public class GuitarSpec {
	private Builder builder;
	private Type type;
	private Wood backWood, topWood;
	private String model;
	private int numStrings;

	public GuitarSpec(Builder builder, String model, Type type, int numStrings, Wood backWood, Wood topWood) {
		this.builder = builder;
		this.type = type;
		this.numStrings = numStrings;
		this.backWood = backWood;
		this.topWood = topWood;
		this.model = model;
	}

	public boolean matches(GuitarSpec otherSpec) {

		if (otherSpec.getBuilder() != otherSpec.getBuilder())
			return false;

		String model = otherSpec.getModel();

		if ((model != null) && (!model.equals("")) && (!model.equals(otherSpec.getModel())))
			return false;
		if (otherSpec.getType() != otherSpec.getType())
			return false;
		if (otherSpec.getBackWood() != otherSpec.getBackWood())
			return false;
		if (otherSpec.getTopWood() != otherSpec.getTopWood())
			return false;

		return true;
	}

	public Builder getBuilder() {
		return builder;
	}

	public Type getType() {
		return type;
	}

	public Wood getBackWood() {
		return backWood;
	}

	public Wood getTopWood() {
		return topWood;
	}

	public String getModel() {
		return model;
	}

	public void setBuilder(Builder builder) {
		this.builder = builder;
	}

	public void setType(Type type) {
		this.type = type;
	}

	public void setBackWood(Wood backWood) {
		this.backWood = backWood;
	}

	public void setTopWood(Wood topWood) {
		this.topWood = topWood;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public int getNumStrings() {
		return numStrings;
	}

	public void setNumStrings(int numStrings) {
		this.numStrings = numStrings;
	}
}
