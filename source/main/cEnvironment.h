/*
 *  cEnvironment.h
 *  Avida
 *
 *  Created by David on 12/2/05.
 *  Copyright 2005-2006 Michigan State University. All rights reserved.
 *  Copyright 1993-2003 California Institute of Technology.
 *
 */

#ifndef cEnvironment_h
#define cEnvironment_h

#ifndef cInstSet_h
#include "cInstSet.h"
#endif
#ifndef cMutationLib_h
#include "cMutationLib.h"
#endif
#ifndef cMutationRates_h
#include "cMutationRates.h"
#endif
#ifndef cReactionLib_h
#include "cReactionLib.h"
#endif
#ifndef cResourceLib_h
#include "cResourceLib.h"
#endif
#ifndef cString_h
#include "cString.h"
#endif
#ifndef cTaskLib_h
#include "cTaskLib.h"
#endif
#ifndef tList_h
#include "tList.h"
#endif

class cReaction;
class cReactionRequisite;
template <class T> class tArray;
class cReactionProcess;
class cReactionResult;
template <class T> class tBuffer;
class cWorld;

class cEnvironment {
private:
  cWorld* m_world;
  
  // Keep libraries of resources, reactions, and tasks.
  cResourceLib resource_lib;
  cReactionLib reaction_lib;
  cMutationLib mutation_lib;
  cTaskLib task_lib;
  cInstSet inst_set;
  cMutationRates mut_rates;

  static bool ParseSetting(cString entry, cString & var_name,
			   cString & var_value, const cString & var_type);
  static bool AssertInputInt(const cString & input, const cString & name,
			     const cString & type);
  static bool AssertInputDouble(const cString & input, const cString & name,
				const cString & type);
  static bool AssertInputBool(const cString & input, const cString & name,
				const cString & type);
  static bool AssertInputValid(void * input, const cString & name,
			       const cString & type, const cString & value);

  bool LoadReactionProcess(cReaction * reaction, cString desc);
  bool LoadReactionRequisite(cReaction * reaction, cString desc);
  bool LoadResource(cString desc);
  bool LoadReaction(cString desc);
  bool LoadMutation(cString desc);

  bool LoadSetActive(cString desc);

  bool TestRequisites(const tList<cReactionRequisite> & req_list,
		      int task_count,
		      const tArray<int> & reaction_count) const;
  void DoProcesses(const tList<cReactionProcess> & process_list,
		   const tArray<double> & resource_count,
		   const double task_quality,
		   cReactionResult & result) const;
private:
  // disabled copy constructor.
  cEnvironment(const cEnvironment &);
public:
  cEnvironment(cWorld* world) : m_world(world), inst_set(world), mut_rates(world) { ; }
  ~cEnvironment() { ; }

  /**
   * Reads the environment from disk.
   **/
  bool Load(const cString & filename);

  /**
   * Reads in a single environment configuration line
   **/
  bool LoadLine(cString line);

  // Interaction with the organisms
  void SetupInputs( tArray<int> & input_array ) const;

  bool TestInput(  cReactionResult & result,
		   const tBuffer<int> & inputs,
		   const tBuffer<int> & outputs,
		   const tArray<double> & resource_count ) const;

  bool TestOutput(  cReactionResult & result,
		    const tBuffer<int> & input_buf,
		    const tBuffer<int> & output_buf,
		    const tBuffer<int> & send_buf,
		    const tBuffer<int> & receive_buf,
		    const tArray<int> & task_count,
		    const tArray<int> & reaction_count,
		    const tArray<double> & resource_count,
		    const tList<tBuffer<int> > & other_inputs,
		    const tList<tBuffer<int> > & other_outputs) const;

  // Accessors
  const cResourceLib & GetResourceLib() const { return resource_lib; }
  const cReactionLib & GetReactionLib() const { return reaction_lib; }
  const cMutationLib & GetMutationLib() const { return mutation_lib; }
  const cTaskLib & GetTaskLib() const { return task_lib; }
  const cMutationRates & GetMutRates() const { return mut_rates; }

  cResourceLib & GetResourceLib() { return resource_lib; }
  cReactionLib & GetReactionLib() { return reaction_lib; }
  cMutationRates & GetMutRates() { return mut_rates; }

  double GetReactionValue(int & reaction_id);
  bool SetReactionValue(const cString & name, double value);
  bool SetReactionValueMult(const cString & name, double value_mult);
  bool SetReactionInst(const cString & name, cString inst_name);
};

#endif
