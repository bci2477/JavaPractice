
public enum Wood {
	ALDER, SITKA, CEDAR;

	public String toString() {
		switch (this) {
		case ALDER:
			return "Alder";
		case SITKA:
			return "Sitka";
		case CEDAR:
			return "Cedar";
		default:
			return null;
		}
	}
}
