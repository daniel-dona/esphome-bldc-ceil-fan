import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import select
from esphome.const import CONF_OPTIONS

from .. import CONF_CEILING_FAN_RF_ID, CeilingFanRf, ceiling_fan_rf_ns

CeilingFanRfSelect = ceiling_fan_rf_ns.class_("CeilingFanRfSelect", select.Select, cg.Component)

TIMER_OPTIONS = ["Off", "1 Hour", "2 Hours", "4 Hours"]

CONFIG_SCHEMA = select.select_schema(CeilingFanRfSelect).extend(
    {
        cv.GenerateID(CONF_CEILING_FAN_RF_ID): cv.use_id(CeilingFanRf),
        cv.Optional(CONF_OPTIONS, default=TIMER_OPTIONS): cv.All(
            cv.ensure_list(cv.string_strict), cv.Length(min=1)
        ),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = await select.new_select(config, options=config[CONF_OPTIONS])
    await cg.register_component(var, config)
    parent = await cg.get_variable(config[CONF_CEILING_FAN_RF_ID])
    cg.add(var.set_parent(parent))
