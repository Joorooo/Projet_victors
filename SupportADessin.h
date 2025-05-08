#pragma once

class PointMateriel;
class Systeme;

class SupportADessin {
	public:
	  virtual ~SupportADessin() = default;
	  
	  // on suppose ici que les supports ne seront ni copiés ni déplacés
	  SupportADessin(SupportADessin const&)            = delete;
	  SupportADessin& operator=(SupportADessin const&) = delete;
	  SupportADessin(SupportADessin&&)            = delete;
	  SupportADessin& operator=(SupportADessin&&) = delete;
	  
	  SupportADessin() = default;

 
	  virtual void dessine(PointMateriel const&) = 0;
	  virtual void dessine(Systeme const&) = 0;
	  virtual void dessine_sur(PointMateriel const&) = 0;


};
