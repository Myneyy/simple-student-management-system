#include <iostream>
#include <vector>
#include <string>



using namespace std;


int eingabe;


struct Schueler {
	string name;
	int alter;
	float note;

	void printInfo() {
		cout << "- " << name << "(Alter: " << alter << ", " << "Note: " << note << ")" << endl;



	}

};


vector<Schueler> schuelerListe;

void MainMenu() {
	cout << "1. Schüler hinzufügen\n";
	cout << "2. Alle Schüler anzeigen\n";
	cout << "3. Schüler Suchen\n";
	cout << "4. Schueler loeschen\n";
	cout << "5. Note eines Schuelers ändern\n";
	cout << "6. Beenden\n";
	cin >> eingabe;
}

void addSchueler() {
	string name_eingabe;
	cout << "Name: ";
	cin >> name_eingabe;

	int alter_eingabe;
	cout << "Alter: ";
	cin >> alter_eingabe;


	float note_eingabe;
	cout << "Note: ";
	cin >> note_eingabe;

	Schueler newSchueler;
	newSchueler.name = name_eingabe;
	newSchueler.alter = alter_eingabe;
	newSchueler.note = note_eingabe;

	schuelerListe.push_back(newSchueler);
	cout << "Neuer Schüler hinzugefügt!\n";
}

void showSchueler() {

	if (schuelerListe.empty()) {
		cout << "Kein Schueler vorhanden!\n";
		return;
	}

	cout << "Alle Schuler: \n";
	for (auto& Schueler : schuelerListe) {
		Schueler.printInfo();
	}

}

void sucheSchueler() {

	bool gefunden = false;
	

	if (schuelerListe.empty()) {
		cout << "Keine Schüler vorhanden!\n";
		return;
	}

	string nameSuche;
	cout << "Gib den Namen ein, den du suchen möchtest: ";
	cin >> nameSuche;

	

	for (Schueler& item : schuelerListe) {
		if (item.name == nameSuche) {
			item.printInfo();
			gefunden = true;
			break;
		}
		
	}

	if (!gefunden) {
		cout << "Schüler nicht gefunden!\n";
	}

	
}

void schuelerLoeschen() {

	bool gefunden = false;


	string nameSuche;
	cout << "Welchen Schüler löschen? ";
	cin >> nameSuche;

	

	for (int positionImVector = 0; positionImVector < schuelerListe.size(); positionImVector++) {
		if (schuelerListe[positionImVector].name == nameSuche) {
			cout << "Schüler " << schuelerListe[positionImVector].name << " gelöscht!\n";
			schuelerListe.erase(schuelerListe.begin() + positionImVector);
			gefunden = true;
			break;
		}
	}

	if (!gefunden) {
		cout << "Kein Schüler mit diesem Namen gefunden!\n";
	}
}

void noteAendern() {
	string namenSuche;
	float neueNote;

	cout << "Welchen Schueler wollen sie bearbeiten\n";
	cin >> namenSuche;

	bool gefunden = false;

	for (int positionImVector = 0; positionImVector < schuelerListe.size(); positionImVector++) {
		if (schuelerListe[positionImVector].name == namenSuche) {
			cout << "Neue Note eingeben: ";
			cin >> neueNote;
			schuelerListe[positionImVector].note = neueNote;
			gefunden = true;
			break;
		}

	}

	if (!gefunden) {
		cout << "Kein Spieler mit diesem Namen gefunden\n";
	}

}

int main() {

	while (true) {
		MainMenu();


		if (eingabe == 1) {
			addSchueler();

		}

		else if (eingabe == 2) {
			showSchueler();

		}

		else if (eingabe == 3) {
			sucheSchueler();

		}

		else if (eingabe == 4) {
			schuelerLoeschen();

		}

		else if (eingabe == 5) {
			noteAendern();
		}

		else if (eingabe == 6) {
			break;
		}

		else {
			cout << "Ungültige eingabe!\n";
		}

		
	}

}
	
