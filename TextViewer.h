#pragma once
#include <iostream>
#include "SupportADessin.h"

class TextViewer : public SupportADessin {
	private:
	  std::ostream& flot;
	
	public:
	  //constructeur
	  TextViewer(std::ostream& flot) : flot(flot) {}
	  
	  void dessine(PointMateriel const& a_dessiner) override;
	  void dessine(Sysyteme const& a_dessiner) override;


 
};
