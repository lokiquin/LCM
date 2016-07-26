//
//  LUMmassmodels.c
//  
//
//  Created by Neutrino mafia on 9/24/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//
{
    //gStyle->SetOptTitle(0);
    gStyle->SetOptDate(0);
    gStyle->SetOptStat(0);
    
    TNtupleD* a2tree = new TNtupleD("a2tree", "a2tree", "kt:lum2");
    TNtupleD* a5tree = new TNtupleD("a5tree", "a5tree", "kt:lum5");
    TNtupleD* a1tree = new TNtupleD("a1tree", "a1tree", "kt:lum1");
    TNtupleD* a9tree = new TNtupleD("a9tree", "a9tree", "kt:lum9");
    
    // ***** Set alpha_o filename here ***** //
    a2tree->ReadFile("DISK_N5907.txt", "kt:lum2");
    cout << "N2903Reported tree has " << a2tree->GetEntries() << " entries" << endl;
    
    // ***** Set alpha filename here ***** //
    a5tree->ReadFile("n5907_MeaganXueSofue.txt", "kt:lum5");
    cout << "XueSof tree has " << a5tree->GetEntries() << " entries" << endl;
    
    // ***** Set alpha filename here ***** //
    a1tree->ReadFile("n5907_MeaganAnatolyB.txt", "kt:lum1");
    cout << "anatB tree has " << a1tree->GetEntries() << " entries" << endl;
    
    // ***** Set alpha filename here ***** //
    a9tree->ReadFile("", "kt:lum9");
    cout << "Xue tree has " << a9tree->GetEntries() << " entries" << endl;
    
    a2tree->Draw("lum2:kt", "", "goff");
    TGraphErrors* a2graph = new TGraphErrors(a2tree->GetEntries(), a2tree->GetV2(), a2tree->GetV1());
    a2graph->SetLineColor(1);
    a2graph->SetLineStyle(1);
    a2graph->SetLineWidth(2);
    
    a5tree->Draw("lum5:kt", "", "goff");
    TGraphErrors* a5graph = new TGraphErrors(a5tree->GetEntries(), a5tree->GetV2(), a5tree->GetV1());
    a5graph->SetLineStyle(5);
    a5graph->SetLineColor(15);
    a5graph->SetLineWidth(3);
    
    a1tree->Draw("lum1:kt", "", "goff");
    TGraphErrors* a1graph = new TGraphErrors(a1tree->GetEntries(), a1tree->GetV2(), a1tree->GetV1());
    a1graph->SetLineStyle(1);
    a1graph->SetLineColor(15);
    a1graph->SetLineWidth(3);
    
    a9tree->Draw("lum9:kt", "", "goff");
    TGraphErrors* a9graph = new TGraphErrors(a9tree->GetEntries(), a9tree->GetV2(), a9tree->GetV1());
    a9graph->SetLineStyle(8);
    a9graph->SetLineColor(1);
    a9graph->SetLineWidth(3);
    
    
    Double_t xMin=0.0, xMax=10.;
    Double_t yMin=0.0, yMax=180.;
    
    a2graph->Draw("APL");
    c1->Update();
    xMin = TMath::Min(c1->GetUxmin(), xMin);
    xMax = TMath::Max(c1->GetUxmax(), xMax);
    yMin = TMath::Min(c1->GetUymin(), yMin);
    yMax = TMath::Max(c1->GetUymax(), yMax);
    
    a5graph.Draw("APL");
    c1->Update();
    xMin = TMath::Min(c1->GetUxmin(), xMin);
    xMax = TMath::Max(c1->GetUxmax(), xMax);
     yMin = TMath::Min(c1->GetUymin(), yMin);
    yMax = TMath::Max(c1->GetUymax(), yMax);
    
    a1graph->Draw("APL");
    c1->Update();
    xMin = TMath::Min(c1->GetUxmin(), xMin);
    xMax = TMath::Max(c1->GetUxmax(), xMax);
     yMin = TMath::Min(c1->GetUymin(), yMin);
    yMax = TMath::Max(c1->GetUymax(), yMax);
    
    a9graph->Draw("APL");
    c1->Update();
    xMin = TMath::Min(c1->GetUxmin(), xMin);
    xMax = TMath::Max(c1->GetUxmax(), xMax);
    yMin = TMath::Min(c1->GetUymin(), yMin);
    yMax = TMath::Max(c1->GetUymax(), yMax);

    TH1I* hAxes = new TH1I("hAxes", " ", 1, xMin, xMax);  
    //infile.c_str()
    hAxes->GetYaxis()->SetRangeUser(yMin, yMax);
    hAxes->SetXTitle("Radius (kpc)");
    hAxes->SetYTitle("Velocity (km/sec)");
    hAxes->GetXaxis()->SetTitleSize(0.05);
    hAxes->GetYaxis()->SetTitleSize(0.05);
    hAxes->Draw();

    
    a2graph->Draw("lsame");
    a5graph->Draw("lsame");
    a1graph->Draw("lsame");
    a9graph->Draw("lsame");
    
    TLegend* leg = new TLegend(0.2, 0.18, 0.4, 0.4);
    leg->SetFillColor(0);
    leg->AddEntry(a2graph, "Reported Luminous Profile ", "l");
    leg->AddEntry(a5graph, "XueSofue", "l"); 
    leg->AddEntry(a1graph, "Klypin (2002) model B   ", "l");
    leg->Draw();

    
}
