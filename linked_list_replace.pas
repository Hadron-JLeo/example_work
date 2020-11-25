// ################################# //
// ###### VARIABLE DEFINITION ###### //
//
type	
tRefIndexListe= ^ tIndexListe;
tIndexListe= record
               index: integer;
               wort: string;
               next: tRefIndexListe
             end;
//
// #################################



// ##### PROCEDURE "ADD" DECLARATION ##### //
//
procedure add(var ioListe:tRefIndexListe; inIndex:integer; inWert:String);
    {
        This procedure adds a node into an already existing dynamic list, if the indexes are equal,
        the indexes of the already existing node must be incremented,
        the same should be done for every non-unique (repeating) index.
    }
    

    // Initialising variables -------
    var
        knoten_einsetzen: tRefIndexListe;
        //
        gegebene_liste, reset_liste, nach_knoten: tRefIndexListe;
        //
        // Knoten Nach dem Knoten der einzusetzen ist
        // 
        cur_index: integer; // Index wo wir gerade drauf sind
        //
        check_1, check_2, check_done, repeating_index: boolean;
    // ##############################

    begin
        gegebene_liste:= ioListe; // Die Liste wo wir Sachen veraendern werden
        reset_liste:= ioListe; // Die Liste womit ich zuruecksetzen kann

        new(knoten_einsetzen);
        knoten_einsetzen^.index:= inIndex;
        knoten_einsetzen^.wort:= inWert;
        knoten_einsetzen^.next := nil;

        nach_knoten:= nil;
        cur_index:= knoten_einsetzen^.index;

        // --- ### Bool Variables ### --- //
        check_1:= (((gegebene_liste^.index = knoten_einsetzen^.index) AND (nach_knoten=nil)));
        // * If index of current node is equal to the index of the node we want to input. AND nach_knoten is still null.
        check_2:= (((gegebene_liste^.index = (knoten_einsetzen^.index-1)) AND (nach_knoten <> nil)));
        // * If index of current node is one less than the index of the node we want to input. AND nach_knoten is not null.
        check_done:= false; // Done with inserting the new node?
        //
        repeating_index:= ((cur_index = gegebene_liste^.index)); // Is the current index repeating?
        // ------------------------------ //


        while (gegebene_liste <> nil) do
            begin
                //gegebene_liste:= gegebene_liste^.next;
                if NOT (knoten_einsetzen^.index < 0) then
                    begin
                        writeln('Nur Zahlen groesser 0');
                        Break;
                    end
                else
                    begin
                        if NOT check_done then
                            begin
                                if check_1 then 
                                    nach_knoten:= gegebene_liste; 
                                    gegebene_liste:= ioListe;
                                    // Wenn der jetzige Index aequivalent zu dem des neuen Knotens ist,
                                    // neuen Knoten an der Stelle dranhaengen
                                    Continue;
                                
                                if check_2 then
                                    knoten_einsetzen^.next:= nach_knoten; 
                                    gegebene_liste^.next:= knoten_einsetzen;
                                    check_done:= true;
                                    // Naechste Stelle des neuen Knotens ist alter Knoten der selben Stelle
                                    // Neuen Knoten dranhaengen

                                    gegebene_liste:= reset_liste; 
                                    // Liste zum ersten Node reseten
                                    Continue;
                            end
                        else
                        // --- if check_done == true |
                            begin
                                cur_index:= gegebene_liste^.index;
                                // Now increment the indexes that come after
                                if repeating_index then
                                // Is the current index repeating?
                                    begin
                                        inc(gegebene_liste^.index);
                                    end;
                            end;
                    end;
                
            end;
       // dispose(knoten_einsetzen); // Speicher wieder freimachen, Object loeschen.
        
    end;
// ##### PROCEDURE "ADD" END ############# //
// ======================================= //
begin

end.
