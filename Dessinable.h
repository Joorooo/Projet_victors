#pragma once
#include "SupportADessin.h"

class Dessinable {
	public:
	  virtual void dessine_sur(SupportADessin& support) const = 0;
	  
	  virtual ~Dessinable() = default;
	  Dessinable(Dessinable const&)            = default;
      Dessinable& operator=(Dessinable const&) = default;
      Dessinable(Dessinable&&)                 = default;
      Dessinable& operator=(Dessinable&&)      = default;
 
      Dessinable() = default;
	
};
