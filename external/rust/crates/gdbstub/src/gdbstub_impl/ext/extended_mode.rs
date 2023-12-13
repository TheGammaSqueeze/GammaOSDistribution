use super::prelude::*;
use crate::protocol::commands::ext::ExtendedMode;

impl<T: Target, C: Connection> GdbStubImpl<T, C> {
    pub(crate) fn handle_extended_mode<'a>(
        &mut self,
        res: &mut ResponseWriter<C>,
        target: &mut T,
        command: ExtendedMode<'a>,
    ) -> Result<HandlerStatus, Error<T::Error, C::Error>> {
        let ops = match target.extended_mode() {
            Some(ops) => ops,
            None => return Ok(HandlerStatus::Handled),
        };

        crate::__dead_code_marker!("extended_mode", "impl");

        let handler_status = match command {
            ExtendedMode::ExclamationMark(_cmd) => {
                ops.on_start().map_err(Error::TargetError)?;
                HandlerStatus::NeedsOk
            }
            ExtendedMode::R(_cmd) => {
                ops.restart().map_err(Error::TargetError)?;
                HandlerStatus::Handled
            }
            ExtendedMode::vAttach(cmd) => {
                ops.attach(cmd.pid).handle_error()?;

                // TODO: sends OK when running in Non-Stop mode
                HandlerStatus::Handled
            }
            ExtendedMode::vRun(cmd) => {
                use crate::target::ext::extended_mode::Args;

                let _pid = ops
                    .run(cmd.filename, Args::new(&mut cmd.args.into_iter()))
                    .handle_error()?;

                // TODO: send a more descriptive stop packet?
                res.write_str("S05")?;
                HandlerStatus::Handled
            }
            // --------- ASLR --------- //
            ExtendedMode::QDisableRandomization(cmd) if ops.configure_aslr().is_some() => {
                let ops = ops.configure_aslr().unwrap();
                ops.cfg_aslr(cmd.value).handle_error()?;
                HandlerStatus::NeedsOk
            }
            // --------- Environment --------- //
            ExtendedMode::QEnvironmentHexEncoded(cmd) if ops.configure_env().is_some() => {
                let ops = ops.configure_env().unwrap();
                ops.set_env(cmd.key, cmd.value).handle_error()?;
                HandlerStatus::NeedsOk
            }
            ExtendedMode::QEnvironmentUnset(cmd) if ops.configure_env().is_some() => {
                let ops = ops.configure_env().unwrap();
                ops.remove_env(cmd.key).handle_error()?;
                HandlerStatus::NeedsOk
            }
            ExtendedMode::QEnvironmentReset(_cmd) if ops.configure_env().is_some() => {
                let ops = ops.configure_env().unwrap();
                ops.reset_env().handle_error()?;
                HandlerStatus::NeedsOk
            }
            // --------- Working Dir --------- //
            ExtendedMode::QSetWorkingDir(cmd) if ops.configure_working_dir().is_some() => {
                let ops = ops.configure_working_dir().unwrap();
                ops.cfg_working_dir(cmd.dir).handle_error()?;
                HandlerStatus::NeedsOk
            }
            // --------- Startup Shell --------- //
            ExtendedMode::QStartupWithShell(cmd) if ops.configure_startup_shell().is_some() => {
                let ops = ops.configure_startup_shell().unwrap();
                ops.cfg_startup_with_shell(cmd.value).handle_error()?;
                HandlerStatus::NeedsOk
            }
            _ => HandlerStatus::Handled,
        };

        Ok(handler_status)
    }
}
