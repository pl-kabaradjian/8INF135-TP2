#include "..\as\timestamp.h"
#include "..\as\trousseau.h"
#include "..\as\chiffrement.h"
#include "..\as\outils.h"
#include <string>

const string cle = "ab5utiqp";
const string nom = "TGS1";

string construireTicketServeur(vector<string> inputs) {
	//[IDC||ADC||IDV||TS2||Duree2]
	return string(inputs[0] + "#" + inputs[1] + "#" + inputs[2] + "#" + to_string(Timestamp::getCurrentTS()) + "#60");
}

int main(int argc, const char* argv[]) {
	//lecture du trousseau
	Trousseau::getTrousseau();
	// Verif rapide des arguments
	verif_argc(argc, 2);
	//Parsing des inputs = IDC#ADC#IDV#Tickettgs
	vector<string> inputs = separeChaine(argv[1],3);
	verif_inputs(inputs, 4);

	//dechiffrement du ticket
	string ticket;
	vector<string> parsed_ticket;
	
	if (verifString(inputs[3]))
	{
		ticket = dechiffrer(cle, inputs[3]);//IDC||ADC||IDtgs||TS1||Duree1
	}
	else
	{
		erreur_and_quit("Caractere indesirable dans le ticket avant dechiffrement");
	}

	if (verifString(ticket)) 
	{
		parsed_ticket = separeChaine(ticket,4);
	}
	else
	{
		erreur_and_quit("Caractere indesirable dans le ticket apres dechiffrement");
	}

	if (parsed_ticket.size() != 5) 
	{
		erreur_and_quit("Ticket non dechiffrable");
	}

	//Verification des champs du ticket
	string idc = inputs[0];
	string adc = inputs[1];
	string idv = inputs[2];
	string ticket_idc = parsed_ticket[0];
	string ticket_adc = parsed_ticket[1];
	string ticket_idtgs = parsed_ticket[2];
	string ticket_ts1 = parsed_ticket[3];
	string ticket_duree1 = parsed_ticket[4];

	if (idc != ticket_idc) 
	{
		erreur_and_quit("IDClients differents");
	}
	else if (adc != ticket_adc)
	{
		erreur_and_quit("Adresses differentes");
	}
	else if (ticket_idtgs != nom) 
	{
		erreur_and_quit("Ce ticket n'est pas pour ce TGS");
	}
	else if (!Trousseau::existe(idv)) {
		erreur_and_quit("Le serveur n'existe pas");
	}
	else if (stol(ticket_ts1) > Timestamp::getCurrentTS()) 
	{
		erreur_and_quit("Temps incoherent");
	}
	else if ((stol(ticket_ts1) + stol(ticket_duree1)) < Timestamp::getCurrentTS()) 
	{
		erreur_and_quit("Le ticket est expire");
	}
	else 
	{
		if (Trousseau::existe(idc) && Trousseau::existe(idv))
		{
			string ticket = construireTicketServeur(inputs);
			if (check_and_cipher(*Trousseau::getCle(idv), &ticket))
			{
				cout << "Voici le ticket : " << add_escape_chars(ticket) << endl;
			}
			else
			{
				erreur("Erreur lors du chiffrement du ticket");
			}

		}
		else
		{
			erreur("Client ou Serveur inconnu");
		}
	}
	system("PAUSE");
	return 0;
}