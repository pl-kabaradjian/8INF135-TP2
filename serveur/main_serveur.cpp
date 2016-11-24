#include "..\as\timestamp.h"
#include "..\as\chiffrement.h"
#include "..\as\outils.h"

const string cle = "8r$iqp!.Q";
const string nom = "V1";

int main(int argc, const char* argv[]) {
	// Verif rapide des arguments
	verif_argc(argc, 2);

	//IDC#ADC#IDV#TicketV
	vector<string> inputs = separeChaine(argv[1],3);

	verif_inputs(inputs, 4);

	string ticket;
	vector<string> parsed_ticket;
	

	if (verifString(inputs[3]))
	{
		ticket = dechiffrer(cle, inputs[3]);//[IDC || ADC || IDV || TS2 || Duree2]
	}
	else
	{
		erreur("Caractere indesirable dans le ticket avant dechiffrement");
		system("PAUSE");
		exit(-1);
	}

	if (verifString(ticket))
	{
		parsed_ticket = separeChaine(ticket, 4);
	}
	else
	{
		erreur("Caractere indesirable dans le ticket apres dechiffrement");
		system("PAUSE");
		exit(-1);
	}

	if (parsed_ticket.size() != 5)
	{
		erreur("Ticket non dechiffrable");
		system("PAUSE");
		exit(-1);
	}

	//Verification des champs du ticket
	string idc = inputs[0];
	string adc = inputs[1];
	string idv = inputs[2];
	string ticket_idc = parsed_ticket[0];
	string ticket_adc = parsed_ticket[1];
	string ticket_idv = parsed_ticket[2];
	string ticket_ts2 = parsed_ticket[3];
	string ticket_duree2 = parsed_ticket[4];

	if (idc != ticket_idc)
	{
		erreur("IDClients differents");
		system("PAUSE");
		exit(-1);
	}
	else if (adc != ticket_adc)
	{
		erreur("Adresses differentes");
		system("PAUSE");
		exit(-1);
	}
	else if (ticket_idv != nom)
	{
		erreur("Ce ticket n'est pas pour ce serveur");
		system("PAUSE");
		exit(-1);
	}
	else if (nom != idv) {
		erreur("Vous ne vous addressez pas au bon serveur");
		system("PAUSE");
		exit(-1);
	}
	else if (stol(ticket_ts2) > Timestamp::getCurrentTS())
	{
		erreur("Temps incoherent");
		system("PAUSE");
		exit(-1);
	}
	else if ((stol(ticket_ts2) + stol(ticket_duree2)) < Timestamp::getCurrentTS())
	{
		erreur("Le ticket est expire");
		system("PAUSE");
		exit(-1);
	}
	else {
		cout << "OK" << endl;
		system("PAUSE");
	}
	return 0;
}