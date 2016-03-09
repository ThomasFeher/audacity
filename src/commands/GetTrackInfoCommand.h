/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2009 Audacity Team
   License: wxwidgets

   Dan Horgan
   Marty Goddard
******************************************************************//**

\file GetTrackInfoCommand.h
\brief Declarations of GetTrackInfoCommand and GetTrackInfoCommandType classes

*//*******************************************************************/

#ifndef __GETTRACKINFOCOMMAND__
#define __GETTRACKINFOCOMMAND__

#include "Command.h"
#include "CommandType.h"

class GetTrackInfoCommandType final : public CommandType
{
public:
   wxString BuildName() override;
   void BuildSignature(CommandSignature &signature) override;
   Command *Create(CommandOutputTarget *target) override;
};

class GetTrackInfoCommand final : public CommandImplementation
{
public:
   GetTrackInfoCommand(CommandType &type, CommandOutputTarget *target)
      : CommandImplementation(type, target)
   { }
   virtual ~GetTrackInfoCommand()
   { }

   bool Apply(CommandExecutionContext context) override;

private:
   void SendBooleanStatus(bool BooleanValue);
};

#endif /* End of include guard: __GETTRACKINFOCOMMAND__ */
